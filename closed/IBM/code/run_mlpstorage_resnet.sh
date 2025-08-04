#!/bin/bash

# Check we're not running on the login node (I keep forgetting to log in to a client node)
if [[ $(hostname) =~ login ]]; then
    echo "ERROR: Can't run this script from a login node"
    exit
fi

# Load argument parser
source "$(dirname "$0")/parse_args.sh"

# Call the parser with CLI args
parse_args "$@"

# User-defined parameters
timestamp=$(date +%Y%m%d_%H%M%S)
hosts_file="$HOME/32_client_nodes"
#hosts_file="$HOME/1_extra_client_nodes"
fs_mountpoint="/gpfs/gpfs0_bench"
## For unet and cosmo
procs_per_node=8 #12                                         # This is the same as saying # of accelerators per node
cores_per_proc=12                                          # Num. cores per MPI proc. Equals or lower than MLPerf's --param reader.read_threads
## For resnet50
#procs_per_node=12                                          # This is the same as saying # of accelerators per node
#cores_per_proc=8                                           # Num. cores per MPI proc. Equals or lower than MLPerf's --param reader.read_threads
client_memory_gb="2016" #2015"                             # Client node dependant. free -g
acc_type="h100"                                            # a100 or h100

echo "NOTICE: You're running $model, $acc_type accelerators, $procs_per_node MPI processes per node and $cores_per_proc cores per MPI process"
read -p "Press Enter to continue or Ctrl+C to abort..."
# MLPerf parameters based on user-defined params
all_clients=$(wc -l < "$hosts_file")
nclients="${nclients:-$all_clients}"                       # If no nclients provided as arg., defaults to all in the hosts_file
max_acc=$(($nclients * $procs_per_node))                   # This is used by mlpstorage to call mpirun -n $max_acc
[[ -z "$nfiles" ]] && num_subfolders=0 || num_subfolders=$((nfiles / 10000))
num_subfolders=120

# Print selected options: $step, $model, $clients
echo "Running with:"
echo "  MLPerf step:       $step"
echo "  Model:             $model"
echo "  Clients:           $nclients"
echo "  Number of files:   $nfiles"
echo "  What if:           $whatif "

# If whatif=True in parse_args because user entered --what-if as a CLI arg,
# then set whatif to "--what-if"
[[ "$whatif" == "True" ]]  && whatif="--what-if" || whatif=""

# We need to do everything mlperf related from a conda virtual environment
# where the benchmark requirements exist. First step is to source the conda
# environment variables and then activate the venv

# NOTICE: THIS PART IS NOT NEEDED IF THE CONDA VENV IS ACTIVATE FROM THE 
# USER'S .bashrc FILE
# source $HOME/miniforge3_aarch/etc/profile.d/conda.sh
# conda activate mlperf_aarch


# Calculate the total number of MPI processes allowed, based on the number of selected
# client nodes and the number of cores required per MPI process.
#
# In MLPerf Storage, the `reader.read_threads` (or `data_loader.read_threads`) parameter
# sets the number of parallel threads used by the data loader (e.g., PyTorch DataLoader)
# to read and preprocess training data. Each thread typically consumes one CPU core.
#
# The default value is 4 threads (set via --param reader.read_threads=4), which can be
# found in model-specific configuration files (e.g., <model><acc_type>_config.yaml).
#
# Therefore, when using the default thread count, we must assign 4 CPU cores per MPI
# process. This is done using the MPI option: --map-by slot:PE=4, which binds each
# process to a set of 4 cores (PE = Processing Elements).
#
# Combined with --bind-to core, this ensures that each MPI process is bound to its
# dedicated core set.
#
# In short: we use 4 cores per MPI process because each MPI process spawns 4 DLIO
# reader threads that run concurrently and require dedicated CPU resources.
calculate_max_mpi_ranks() {
    local total_available_mpi_procs=0
    local ncores=$(nproc)
    cpp=$1
    clients=$2
    total_procs_requested=$3
    local max_mpi_procs_per_client=$(( ncores / cpp ))
    local max_total_mpi_procs=$(( ncores * clients / cpp ))
    
    # We'll assume all nodes have the same amount of cores than the executing node
    ncores=$(nproc 2>/dev/null)

    echo "Total MPI procs (ranks) possible: $max_total_mpi_procs"
    if (( total_procs_requested > max_total_mpi_procs )); then
        echo "Error: Requested $total_procs_requested MPI ranks exceed the total maximum allowed ($max_total_mpi_procs) for this run"
	echo "Reduce the number of procs_per_node from $procs_per_node to max $max_mpi_procs_per_client" 
        return 1
    else
        echo "Requested MPI ranks ($total_procs_requested) are within the limit."
    fi
}

# Verify that the requested cores-per-process ratio is achievable, 
# assuming each node has the same number of cores
if ! calculate_max_mpi_ranks $cores_per_proc $nclients $max_acc; then
    exit 1
fi

# Handle user arguments
case "$step" in
    size)
	size_resdir="${model}_datasize_results/${nclients}N_${max_acc}ACC"
	mkdir -p "$size_resdir"
	output_file="${size_resdir}/mlperf_${model}_datasize_${nclients}N_${max_acc}ACC_$timestamp.out"
        exec > >(tee -a $output_file) 2>&1
        echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Running datasize..."
	hosts=$(cat $hosts_file | head -$nclients | sed "s/$/:$procs_per_node/" | paste -sd,)
        echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Hosts assigned: $hosts"
        mlpstorage training datasize \
            --hosts=$hosts \
            --model $model \
            --num-client-hosts $nclients \
            --client-host-memory-in-gb $client_memory_gb \
            --max-accelerators $max_acc \
            --accelerator-type $acc_type \
            --results-dir $size_resdir \
        ;;

    gen)
	resdir="${model}_datagen_results/${nclients}N_${max_acc}ACC"
	mkdir -p "$resdir"
	output_file="${resdir}/mlperf_${model}_datagen_${nclients}N_${max_acc}ACC_${acc_type}_$timestamp${whatif//--/_}.out"
	exec > >(tee -a $output_file) 2>&1
        echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Running datagen..."
	hosts=$(cat $hosts_file | head -$nclients | sed "s/$/:$procs_per_node/" | paste -sd,)
	#hosts="localhost:${procs_per_node}"
	echo "Running from host $hosts"
	datadir="${fs_mountpoint}/${model}_${nclients}N_${max_acc}ACC_dataset"
	echo "Datadir location: $datadir"
	echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Hosts assigned and tasks (accelerators) per host: ${hosts}"
        mlpstorage training datagen \
            --hosts=$hosts \
            --model=$model \
            --exec-type mpi \
	    --mpi-params "--bind-to core" "--map-by slot:PE=$cores_per_proc" \
            --param dataset.num_files_train=$nfiles \
            --param dataset.num_subfolders_train=$num_subfolders \
            --num-processes $max_acc \
            --results-dir $resdir \
            --data-dir $datadir \
	    $whatif
        ;;

    run)
	resdir="${model}_run_results/${nclients}N_${max_acc}ACC"
	mkdir -p "$resdir"
	output_file="${resdir}/mlperf_${model}_run_${nclients}N_${max_acc}ACC_${acc_type}_$timestamp${whatif//--/_}.out"
        exec > >(tee -a $output_file) 2>&1
        echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Running benchmark..."
	hosts=$(cat $hosts_file | head -$nclients | sed "s/$/:$procs_per_node/" | paste -sd,)
	datadir="${fs_mountpoint}/${model}_${nclients}N_${max_acc}ACC_dataset/${model}"
	datadir="/gpfs/gpfs0_bench/resnet50_32N_256ACC_dataset/"
	echo "Datadir location: $datadir"
	#nfiles=$(find $datadir -type f | wc -l)
	#num_subfolders=$(($nfiles / 10000)) # 10K per folder as suggested by the tool
	echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Hosts assigned and tasks (accelerators) per host: $hosts"
        mlpstorage training run \
            --hosts=$hosts \
            --model=$model \
            --num-client-hosts $nclients \
            --client-host-memory-in-gb $client_memory_gb \
	    --exec-type mpi \
	    --mpi-params "--bind-to core" "--map-by slot:PE=$cores_per_proc" \
            --accelerator-type $acc_type \
            --num-accelerators $max_acc \
            --data-dir $datadir \
            --results-dir $resdir \
	    --param dataset.num_subfolders_train=$num_subfolders \
	    --param dataset.num_files_train=$nfiles \
	    --param reader.computation_threads=2 \
	    --closed \
	    $whatif
        ;;

esac
echo "Output file: $output_file"
#--param dataset.num_files_train=$num_files \
#            --param dataset.num_subfolders_train=$num_subfolders \
#--param reader.read_threads=1 \
