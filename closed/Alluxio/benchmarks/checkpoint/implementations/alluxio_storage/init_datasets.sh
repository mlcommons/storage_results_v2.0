#!/bin/bash
set -e

# Start Alluxio
# alluxio-start.sh local

# Mount your S3
# alluxio fs mount /checkpoint s3://your-checkpoint-bucket

# If your checkpoint has been already mounted within Alluxio cluster, skip above step

# Create FUSE directory
mkdir -p /mnt/alluxio-fuse

# Mount Alluxio FUSE
alluxio-fuse mount /mnt/alluxio-fuse

# Option: warm up checkpoint directory data
# alluxio fs load /mnt/alluxio-fuse/llama3-checkpoints

