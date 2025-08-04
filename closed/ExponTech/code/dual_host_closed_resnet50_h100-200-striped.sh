#!/bin/bash
# ExponTech script to run single host submission Closed - 16 accelerators
# Run on a single A100 again a single client node
# The cache is cleaned at each iteration
# set -x / -e (all command are looged, any failed command stops the script)

set -e
set -x

modelname="resnet50"
localdisks=(/dev/nvme1n2 /dev/nvme4n2)  # used only for mount_wds_fromlv()
localdisk="/dev/nvme0n1"  # used for mount_wds_frompv()
vg_name="expon_vg"
lv_name="expon_lv"
mount_point="/mnt/mlperfbenchmark"
TRIPE_SIZE="256"
lv_size="100%FREE"
report_root="/root/expontech/Closed/ExponTech/results/ExponTech_WADP_Single_JBOF_With_4DPU_2Client/"

# The tuning that can be played with in CLOSED
#export nb_accelerator=128
export nb_accelerator=200
export nb_hosts=2
export host_ip="10.10.225.50,10.10.226.50"
export type_accelerator="h100"
export path_datafolder="/mnt/mlperfbenchmark"
export nb_readerthreads=6
export nb_computationthreads=8
export TRAINONLY="True" # True or False
export MOUNT_OPTIONS="allocsize=1m,largeio"
# Define global variable for available memory in client
export AVAILABLE_MEM_GB=512


# Allow OMPI to run any number of process
export OMPI_MCA_rmaps_base_oversubscribe=1
export OMPI_ALLOW_RUN_AS_ROOT=1
export OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1
export PMIX_MCA_gds=hash
export OMPI_MCA_btl=self,tcp

cleanup_lv() {
    local vg_name="$1"
    local lv_name="$2"
    local mount_point="$3"

    # Check input args
    if [[ -z "$vg_name" || -z "$lv_name" || -z "$mount_point" ]]; then
	    echo "ERROR：missing input parameters (VG name, LV name or mount point)!"
        return 1
    fi

    # 1. Check and remove mount point from /etc/fstab
    if grep -q "$mount_point" /etc/fstab; then
        echo "Found mount point $mount_point in /etc/fstab, removing the entry..."
        # Create a backup of fstab
        cp /etc/fstab /etc/fstab.bak.$(date +%Y%m%d%H%M%S)
        # Remove the line containing the mount point
        sed -i "\@$mount_point@d" /etc/fstab
        echo "Removed $mount_point from /etc/fstab"
    fi

    if mount | grep -q "$mount_point"; then
        umount "$mount_point" || { echo "Failed to umount $mount_point !"; return 1; }
    fi
    rm -rf "$mount_point" 2>/dev/null

    # Remove LV
    if lvs "/dev/$vg_name/$lv_name" &>/dev/null; then
        lvremove -f "/dev/$vg_name/$lv_name" || { echo "Failed to remove  LV $lv_name !"; return 1; }
    fi

    # Remove VG
    if vgs "$vg_name" &>/dev/null; then
        vgremove -f "$vg_name" || { echo "Failed to remove VG $vg_name !"; return 1; }
    fi

    # Remove PV
    for disk in "${localdisks[@]}"; do
        if pvs "$disk" &>/dev/null; then
            pvremove -f "$disk" || { echo "Failed to remove PV $disk !"; return 1; }
        fi
    done

    echo "Clean complete: $mount_point and $vg_name/$lv_name are all cleaned"
}

create_vg() {
    local vg_name="$1"
    shift
    local disks=("$@")

    for disk in "${disks[@]}"; do
        if lsblk "$disk" | grep -q "mounted\|lvm"; then
            echo "Error: $disk already in use!"
            return 1
        fi
        pvcreate -y "$disk" || { echo " PV Failed to create $disk."; return 1; }
    done

    vgcreate "$vg_name" "${disks[@]}" || { echo "Failed to create VG $vg_name"; return 1; }
    echo "Success to create VG  $vg_name"
}

create_lv() {
    local vg_name="$1"
    local lv_name="$2"
    local mount_point="$3"
    local lv_size="$4"  # e.g.: "10G" or "100%FREE"
    local fs_type="${5:-xfs}"  # default: XFS，optional: ext4

    lvcreate -y --type striped -i ${#localdisks[@]} -I ${TRIPE_SIZE}k -n "$lv_name" -l "$lv_size" "$vg_name" || { echo "Failed to create LV $lv_name!"; return 1; }

    case "$fs_type" in
        xfs) mkfs.xfs -f -d su=${TRIPE_SIZE}k,sw="${#localdisks[@]}" -b size=4096 -s size=512 "/dev/$vg_name/$lv_name" ;;
        ext4) mkfs.ext4 "/dev/$vg_name/$lv_name" ;;
        *) echo "Unsupported filesystem $fs_type"; return 1 ;;
    esac

    mkdir -p "$mount_point"
    mount "/dev/$vg_name/$lv_name" "$mount_point" || { echo "Mount LV failed!"; return 1; }

    echo "/dev/$vg_name/$lv_name $mount_point $fs_type defaults 0 0" | sudo tee -a /etc/fstab >/dev/null
    echo "LV $lv_name created and mounted at $mount_point!"
}


mount_wds_fromlv() {

    # remove old mountpoint, lv vg if vg exist
    # 
    if vgs "$vg_name" &>/dev/null; then
        echo "VG $vg_name exists, will clean all"
    	cleanup_lv "$vg_name" "$lv_name" "$mount_point"
    else
        echo "VG $vg_name does not exist, preparing ..."
    fi

    # Create  VG
    create_vg "$vg_name" "${localdisks[@]}" || exit 1

    # Create LV and mounted 
    create_lv "$vg_name" "$lv_name" "$mount_point" "$lv_size" "xfs" || exit 1

    # Verifty
    df -h "$mount_point"
    lvs
}

mount_wds_frompv() {

    # check the device is valid
    if [[ ! -b "$localdisk" ]]; then
        echo "ERROR: '$localdisk' is an invalid block device"
        return 1
    fi    

    # umount the old one if mounted
    if grep -qs "$mount_point" /proc/mounts; then
        echo "umount the old mount point: $mount_point..."

        if ! umount "$mount_point"; then
            echo "ERROR: Failed to umount $mount_point !"
            return 1
        fi
    fi

    # Create mount point if needed
    if [[ ! -d "$mount_point" ]]; then
        echo "Create mount point $mount_point..."
        mkdir -p "$mount_point" || {
            echo "ERROR: Failed to create mount point:  $mount_point !"
            return 1
        }
    fi    

    # Format the specifed device
    echo "Format $localdisk into XFS..."
    if ! mkfs.xfs -f "$localdisk"; then
        echo "ERROR: Failed to format $localdisk into XFS !"
        return 1
    fi

    # Mount 
    echo "Mount $localdisk into $mount_point..."
    if ! mount "$localdisk" "$mount_point"; then
        echo "ERROR: Failed to moount $localdisk !"
        return 1
    fi

    echo "Complete:  $localdisk is already mounted to $mount_point"
    df -h "$mount_point"
}

clear_caches() {
    # Clear cache on client
    sync; echo 3 > /proc/sys/vm/drop_caches
    # Print current available MEM
    echo "Available MEM: $(awk '/MemAvailable/ {printf "%.2f GiB\n", $2/1024/1024}' /proc/meminfo)"
}

export results_dir="node${nb_hosts}_${modelname}_${type_accelerator}_${nb_accelerator}_results"

# Generate more training file for flexitility
datagen_files_num=$(mlpstorage training datasize \
	--hosts ${host_ip} \
	-m ${modelname} \
	--client-host-memory-in-gb ${AVAILABLE_MEM_GB} \
	--max-accelerators $(( nb_accelerator * 2 + 192 )) \
	--num-client-hosts ${nb_hosts} \
	--accelerator-type ${type_accelerator}  \
	--results-dir ${results_dir} 2>&1 \
	| grep "Number of training files" | awk '{print $7}')

# Clean the files_num value (critical fix)
clean_datagen_files_num=$(echo "${datagen_files_num}" | sed 's/\x1b\[[0-9;]*m//g')

if [ "$TRAINONLY" = "False" ]; then
    echo "Preparing Dataset for Training benchmark....... "
    mount_wds_fromlv
    #mount_wds_frompv  # switch to use single block device or lvm
    # generate dataset
    # Example
    #mlpstorage training datagen \
#	--hosts 127.0.0.1,127.0.0.1 \
#	--model resnet50 \
#	--num-processes 96 \
#	--param dataset.num_files_train=192 \
#	--data-dir /mnt/nvme/test_data \
#	--results-dir /root/mlpstorage_test_results \
#	--allow-run-as-root
    mlpstorage training datagen \
	--hosts ${host_ip} \
	--model ${modelname} \
	--mpi-params "--mca btl_tcp_if_include enp195s0f0np0" \
	--num-processes 64 \
	--data-dir /mnt/mlperfbenchmark \
	--param dataset.num_files_train=${clean_datagen_files_num} \
	--allow-run-as-root \
	--results-dir ${results_dir} \
    2>&1 | tee data_generation_${nb_hosts}node_${modelname}_${nb_accelerator}_${type_accelerator}_${clean_file_num}.log
fi

# traing files number for run
run_files_num=$(mlpstorage training datasize \
        --hosts ${host_ip} \
        -m ${modelname} \
        --client-host-memory-in-gb ${AVAILABLE_MEM_GB} \
        --max-accelerators ${nb_accelerator} \
        --num-client-hosts ${nb_hosts} \
        --accelerator-type ${type_accelerator}  \
        --results-dir ${results_dir} 2>&1 \
        | grep "Number of training files" | awk '{print $7}')

# Clean the files_num value (critical fix)
clean_run_files_num=$(echo "${run_files_num}" | sed 's/\x1b\[[0-9;]*m//g')

for iter in {0..4}; do
    export logfile="result_${nb_hosts}node_${modelname}_${nb_accelerator}_${type_accelerator}_iter${iter}.log"
    
    clear_caches

    # Random sleep between runs
    random_sleep=$(( RANDOM % 121 + 180 ))  # 60 + (0~240)
    echo "Performing a rand sleep for ${random_sleep} seconds"
    sleep "$random_sleep"

    mlpstorage training run --closed \
	--hosts ${host_ip} \
	--num-client-hosts ${nb_hosts} \
	--mpi-params "--mca btl_tcp_if_include enp195s0f0np0" \
	--client-host-memory-in-gb ${AVAILABLE_MEM_GB} \
	--num-accelerators ${nb_accelerator} \
	--accelerator-type ${type_accelerator} \
	--model ${modelname}  \
	--data-dir ${path_datafolder} \
	--results-dir ${results_dir} \
	--param dataset.num_files_train=${clean_run_files_num} \
	--param reader.computation_threads=${nb_computationthreads} \
	--param reader.read_threads=${nb_readerthreads} \
    2>&1 | tee ${logfile}
done

# Copy benchmark result to report root

#cp -rf ${results_dir}/training ${report_root}/
#rm -rf ${results_dir}


# Generate report for ${modelname}_${nb_accelerator}_${type_accelerator}
#mlpstorage reports reportgen --results-dir ${report_root}
mlpstorage reports reportgen --results-dir ${results_dir}

echo "Mission Complete for ${modelname}-${type_accelerator}-${nb_accelerator}"
