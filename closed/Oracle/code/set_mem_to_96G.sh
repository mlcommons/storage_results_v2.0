#!/bin/bash

set -e

GRUB_FILE="/etc/default/grub"
BACKUP_FILE="/etc/default/grub.bak"

# Backup the original grub file
cp $GRUB_FILE $BACKUP_FILE

# Only modify if mem= is not already present
if ! grep -q "mem=96G" $GRUB_FILE; then
    sed -i 's/GRUB_CMDLINE_LINUX_DEFAULT="/GRUB_CMDLINE_LINUX_DEFAULT="mem=96G /' $GRUB_FILE
fi
