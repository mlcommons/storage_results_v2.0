# User-defined parameters
timestamp=$(date +%Y%m%d_%H%M%S)
hosts_file="$HOME/32_client_nodes"
hosts_file_fn="$HOME/32_client_nodes_full_names"
fs_mountpoint="/gpfs/gpfs0_bench"
fs_name="gpfs0_bench"
client_memory_gb="2015"                             # Client node dependant. free -g
#nclients=2

# Help message function for correct script print_help
print_help() {
    echo "Usage: ./run_checkpointing.sh {llama3-8b|llama3-70b|llama3-405b|llama3-1t} {nclients} {ppn} {umount|cachectl} [--what-if]"
    echo
    cat <<EOF
    llama3-8b:   Max 8 total MPI procs (min 4 MPI procs per client node)
    llama3-70b:  Max 64 total MPI procs (min 4 MPI procs per client node)
    llama3-405b: Max 512 total MPI procs (min 4 MPI procs per client node)
    llama3-1t:   Max 1024 total MPI procs (min 4 MPI procs per client node)
    nclients:    Number of clients for the test (restrictions apply depending on total MPI procs per model and min MPI procs per client)
    ppn:         Number of MPI processes per node (1 proc is 1 simulated accelerator). Min allowed is 4.
    umount:      Unmount and re-mount the GPFS filesystem on all client nodes
    cachectl:    Use mmcachectl to find cached files and uncache them with gpfsperf
    --what-if:   View the configuration that would execute and the associated command
    
EOF
}

clear_cache() {
    case $1 in
        umount)
	    set -e
	    #sudo su
            echo "Unmounting ${fs_name}..."
	    sudo /usr/lpp/mmfs/bin/mmumount $fs_name -N $hosts_file_fn
            sleep 1
            echo "Now mounting  ${fs_name}..."
            sudo /usr/lpp/mmfs/bin/mmmount $fs_name -N $hosts_file_fn
            sleep 1
	    : <<'END_COMMENT'
            No need to check if the nodes have the filesystem mounted if set -e is specified. Script will abort execution
	    for node in $(cat "$nodes_file"); do
                echo "Checking if $fs_name is mounted on $node..."

                while ! ssh "$node" mmlsmount $fs_name -L | egrep -q "$node" ; do
                    echo "${fs_name} not mounted on ${node}. Retrying in 5 seconds..."
                    sleep 5
                done
                echo "${fs_name} is now mounted on ${node}"
            done
END_COMMENT
	    ;;

        cachectl) 
	    set -e
            for file in $(sudo /usr/lpp/mmfs/bin/mmcachectl show --device $fs_name --show-filename | awk ' { print $11 } ' | grep "^/") ; do
                #echo "/usr/lpp/mmfs/samples/perf/gpfsperf uncache ${file}"
                sudo /usr/lpp/mmfs/samples/perf/gpfsperf uncache $file
            done
	    echo "Finished uncache phase"
	    ;;
    esac

}

# Check for arg help|h 
for arg in "$@"; do
    if [[ "$arg" == "-h" || "$arg" == "--help" ]]; then
        print_help
	exit 1
    fi
done

# Check number of arguments
if [[ $# -lt 4 ]]; then
    echo "Error: Expected at least 4 arguments"
    print_help
    exit 1
fi

# For CLOSED submissions, participants are not permitted to change the total number of simulated accelerators. 
# However, they may adjust the number of simulated accelerators per host, as long as each host uses more than 
# 4 simulated accelerators.
# llama3-8b   - Max 8 total MPI procs
# llama3-70b  - Max 64 total MPI procs
# llama3-405b - Max 512 total MPI procs
# llama3-1t   - Max 1024 total MPI procs
declare -A models
models=(
  [llama3-8b]=8
  [llama3-70b]=64
  [llama3-405b]=512
  [llama3-1t]=1024
)

# Choosen parameters (taken from command line as args)
model=$1
nclients=$2
ppn=$3
clear_cache_method=$4
whatif=$5
total_req_procs=$(( nclients * ppn ))
checkpoint_folder="${fs_mountpoint}/${model}"
max_allowed_procs="${models[$model]}"
procs_per_node=$(( max_allowed_procs / nclients ))
checkpoint_resdir="${model}_checkpoint_results/${nclients}N_${max_allowed_procs}ACC"
# Get the model's max processes

# Validate total procs doesn't exceed model max
if (( total_req_procs > max_allowed_procs )); then
  echo "Error: Model ${model} supports a maximum of ${max_allowed_procs} MPI processes. You requested ${total_req_procs}"
  exit 1
fi

# Validate min 4 procs per node
if (( ppn < 4 )); then
  echo "Error: You must run at least 4 MPI processes per node. You requested ${ppn} across ${nclients} nodes"
  exit 1
# Validate cores per node are not exceeded. Our nodes have 96 cores each.
elif (( ppn > 96 )); then
  echo "Error: Exceeds available cores per node (96). You requested ${ppn} procs per node"
  exit 1
fi

echo "Configuration is valid."

#echo $model $nclients $clear_cache $whatif
# Checkpoint folder is the directory in the filesystem where the benchmarking data will be created
#output_file="${checkpoint_resdir}/mlperf_${model}_checkpointing_${nclients}N_${max_acc}ACC_$timestamp${whatif//--/_}.out"heckpoint_folder="${fs_mountpoint}/${model}_${nclients}N_${max_allowed_procs}ACC"
#exec > >(tee -a $output_file) 2>&1
echo "Checkpoints datadir: ${checkpoint_folder}"
hosts=$(cat $hosts_file | head -$nclients | sed "s/$/:$procs_per_node/" | paste -sd,)
echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Hosts assigned: $hosts"
echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Running checkpointing WRITE..."
mlpstorage checkpointing run \
    --model $model \
    --hosts=$hosts \
    --num-processes $max_allowed_procs \
    --checkpoint-folder $checkpoint_folder \
    --client-host-memory-in-gb $client_memory_gb \
    --results-dir $checkpoint_resdir \
    --num-checkpoints-read 0 \
    --closed \
    $whatif

echo "Dropping caches with $clear_cache_method"
clear_cache $clear_cache_method
echo "$(date +"%Y-%m-%d %H:%M:%S")|INFO: Running checkpointing READ..."

mlpstorage checkpointing run \
    --model $model \
    --hosts=$hosts \
    --num-processes $max_allowed_procs \
    --checkpoint-folder $checkpoint_folder \
    --client-host-memory-in-gb $client_memory_gb \
    --results-dir $checkpoint_resdir \
    --num-checkpoints-write 0 \
    --closed \
    $whatif

echo "Output file: $output_file"
