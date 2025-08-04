  if [ "$#" -ne 3 ]; then
    echo "Usage: workaround_for_mlperfv2_issue172.sh <num_files> <model_name> <num_processes>" >&2
    exit 1
  fi

  num_files=$1
  model_name=$2
  num_processes=$3
  samples_per_file=0

  case "$model_name" in
    "unet3d")
      # From unet3d_*.yaml                                                                                                                                                                                                                                                                                                                                        
      samples_per_file=1
      ;;
    "cosmoflow")
      # From cosmoflow_*.yaml                                                                                                                                                                                                                                                                                                                                     
      samples_per_file=1
      ;;
    "resnet50")
      # From resnet50_*.yaml                                                                                                                                                                                                                                                                                                                                      
      samples_per_file=1251
      ;;
    *)
      echo "Error: Invalid model name '$model_name'. Supported models are: unet3d, cosmoflow, resnet50." >&2
      exit 1
      ;;
  esac

  x_total_samples=$(( num_files * samples_per_file ))
  y_divisible_samples=$(( (x_total_samples + num_processes - 1) / num_processes * num_processes ))
  new_num_files=$(( (y_divisible_samples + samples_per_file - 1) / samples_per_file ))

  echo "$new_num_files"

