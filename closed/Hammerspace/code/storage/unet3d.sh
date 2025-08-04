#!/bin/bash

# ---- GLOBALS ----
datagen_host_list=`echo {141..144} 111 112`
train_host_list=`echo 101`
host_count=$(echo $train_host_list | wc -w)
host_pdsh_list=$(echo $train_host_list | cut -d ' ' -f 1)
hosts_string=''
gpus=28
sizer_files=98000
client_mem=1024
subfolders_totrain=100
data_dir="/mnt/hs_test/data/unet3d"
results_dir="/mnt/hs_test/Hammerspace_unet3d_1Tier0_H100"
model="unet3d"
accelerator_type="h100"
train_params='--param reader.odirect=true --param reader.read_threads=7 --param reader.prefetch_size=0 --closed'
extra_files=0
datagen_procs=96
num_file_record="${data_dir}/num_files"
whatif=false
script_mode="$1"

# ---- FUNCTIONS ----
workaround_for_mlperfv2_issue172() {
  if [ "$#" -ne 3 ]; then
    echo "Usage: workaround_for_mlperfv2_issue172 <num_files> <model_name> <num_processes>" >&2
    exit 1
  fi

  local num_files=$1
  local model_name=$2
  local num_processes=$3
  local samples_per_file=0

  case "$model_name" in
    "unet3d")
      samples_per_file=1
      ;;
    "cosmoflow")
      samples_per_file=1
      ;;
    "resnet50")
      samples_per_file=1251
      ;;
    *)
      echo "Error: Invalid model name '$model_name'. Supported models are: unet3d, cosmoflow, resnet50." >&2
      exit 1
      ;;
  esac

  local x_total_samples=$(( num_files * samples_per_file ))
  local y_divisible_samples=$(( (x_total_samples + num_processes - 1) / num_processes * num_processes ))
  local new_num_files=$(( (y_divisible_samples + samples_per_file - 1) / samples_per_file ))

  echo "$new_num_files"
}

build_host_strings() {
  local list="$1"
  hosts_string=''
  host_pdsh_list=$(echo $list | cut -d ' ' -f 1)
  for hostip in $list; do
    if [ "$host_pdsh_list" != "$hostip" ]; then
      host_pdsh_list="${host_pdsh_list},${hostip}"
    fi
    hosts_string="${hosts_string} 192.168.0.${hostip}:96"
  done
}

run_sizer() {
  [ "$script_mode" = "sizer" ] && echo "Running sizer..."

  output=$(mlpstorage training datasize -m ${model} --client-host-memory-in-gb ${client_mem} \
    --max-accelerators ${gpus} --num-client-hosts ${host_count} \
    --accelerator-type ${accelerator_type} --results-dir ${results_dir} \
    --param dataset.num_subfolders_train=${subfolders_totrain} 2>&1)

  [ "$script_mode" = "sizer" ] && printf "%s\n" "$output"

  recommended_files=$(echo "$output" | grep -oP 'Number of training files: \K[0-9]+')

  if [ -n "$recommended_files" ]; then
    [ "$script_mode" = "sizer" ] && echo "Recommended training files from sizer: $recommended_files"
    sizer_files=$recommended_files
  else
    echo "Warning: Could not determine recommended training files from sizer output. Using default: $sizer_files"
  fi
}

datagen() {
  build_host_strings "$datagen_host_list"
  run_sizer

  datagen_files=$((sizer_files + extra_files))
  echo $datagen_files > "$num_file_record"

  echo "Running datagen for $datagen_files files..."
  cmd="mlpstorage training datagen --hosts ${hosts_string} --model=${model} --exec-type=mpi \
    --param dataset.num_subfolders_train=${subfolders_totrain} \
    --param dataset.num_files_train=${datagen_files} \
    --num-processes=${datagen_procs} --results-dir=${results_dir} \
    --data-dir=${data_dir} --allow-run-as-root \
    --oversubscribe --mpi-params \"--map-by node:OVERSUBSCRIBE\""

  if [ "$whatif" = true ]; then
    echo "[WHATIF] Would run: $cmd"
  else
    eval $cmd
  fi
}

train() {
  build_host_strings "$train_host_list"
  run_sizer

  if [ -f "$num_file_record" ]; then
    recorded_files=$(cat "$num_file_record")
    if [ "$sizer_files" -gt "$recorded_files" ]; then
      echo "Error: sizer recommends $sizer_files files but $recorded_files were generated. Aborting."
      exit 1
    fi
  else
    echo "Warning: Could not find $num_file_record. Proceeding without validation."
  fi

  echo "Preparing to train..."
  files=$(workaround_for_mlperfv2_issue172 $sizer_files ${model} $gpus)

  echo "count: $host_count"
  echo "pdsh_list: $host_pdsh_list"
  echo "hosts_string: $hosts_string"
  echo "sizer_files: $sizer_files actual_files: $files"

  for phase in warmup run1 run2 run3 run4 run5; do
    drop_cmd="pdsh -w 192.168.0.[$host_pdsh_list] \"echo 3 > /proc/sys/vm/drop_caches\""
    phase_results_dir="${results_dir}/${phase}"
    run_cmd="mlpstorage training run --hosts ${hosts_string} --num-client-hosts ${host_count} \
      --client-host-memory-in-gb ${client_mem} --num-accelerators ${gpus} \
      --accelerator-type ${accelerator_type} --model ${model} \
      --data-dir ${data_dir} \
      --results-dir ${phase_results_dir} \
      --param dataset.num_files_train=${files} --allow-run-as-root \
      --oversubscribe --param dataset.num_subfolders_train=${subfolders_totrain} \
      ${train_params} --mpi-params \"--map-by node:OVERSUBSCRIBE\""

    if [ "$whatif" = true ]; then
      echo "[WHATIF] Would run: $drop_cmd"
      echo "[WHATIF] Would run: $run_cmd"
    else
      eval $drop_cmd
      eval $run_cmd
    fi
  done
}

# ---- MAIN ENTRY ----
if [ "$2" == "--whatif" ]; then
  whatif=true
fi

case "$script_mode" in
  sizer)
    run_sizer
    ;;
  datagen)
    datagen
    ;;
  train)
    train
    ;;
  *)
    echo "Usage: $0 {sizer|datagen|train} [--whatif]"
    exit 1
    ;;
esac

