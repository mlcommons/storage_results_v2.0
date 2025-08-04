#!/bin/bash
# ExponTech script to run single host submission Closed - 16 accelerators
# Run on a single A100 again a single client node
# The cache is cleaned at each iteration
# set -x / -e (all command are looged, any failed command stops the script)

set -e
set -x

localdisks=(/dev/nvme7n2 /dev/nvme4n2)  # used only for mount_wds_fromlv()
vg_name="expon_vg"
lv_name="expon_lv"
mount_point="/mnt/mlperfbenchmark"
TRIPE_SIZE="256"
lv_size="100%FREE"

# The tuning that can be played with in CLOSED
export TRAINONLY="False" # True or False
export MOUNT_OPTIONS="allocsize=1m,largeio"



cleanup_lv() {
    local vg_name="$1"
    local lv_name="$2"
    local mount_point="$3"

    # Check input args
    if [[ -z "$vg_name" || -z "$lv_name" || -z "$mount_point" ]]; then
	    echo "ERROR：missing input parameters (VG name, LV name or mount point)!"
        return 1
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


mount_wadp_fromlv() {

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

    # create folder in advance
    mkdir -p ${mount_point}/resnet50/index/train
    mkdir -p ${mount_point}/resnet50/train
    mkdir -p ${mount_point}/resnet50/valid
    mkdir -p ${mount_point}/resnet50/test

    # Verifty
    df -h "$mount_point"
    lvs
    chmod 777 -R "$mount_point"
    tree "$mount_point"
}

mount_wadp_frompv() {

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
    if ! mount -o ${MOUNT_OPTIONS} "$localdisk" "$mount_point"; then
        echo "ERROR: Failed to moount $localdisk !"
        return 1
    fi

    echo "Complete:  $localdisk is already mounted to $mount_point"
    df -h "$mount_point"
}

mount_wadp_fromlv

