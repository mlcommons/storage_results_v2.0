#!/bin/bash
set -e

# Start Alluxio if needed
alluxio-start.sh local

# Mount S3 bucket
alluxio fs mount /s3bucket s3://your-bucket-name

# (Optional) Warm-up or preload
# alluxio fs load /s3bucket

# Mount via FUSE
mkdir -p /mnt/alluxio-fuse
alluxio-fuse mount /mnt/alluxio-fuse

