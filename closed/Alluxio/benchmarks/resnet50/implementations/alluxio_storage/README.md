# MLPerf Storage Benchmark - resnet50 with Alluxio FUSE + AWS S3

## Overview

This directory contains the implementation for the MLPerf Storage v2.0 'resnet50' benchmark using Alluxio 3.6.0 in FUSE mode mounted on AWS S3.

This implementation uses the official MLCommons Storage benchmark code from:

git clone -b v2.0-rc0 https://github.com/mlcommons/storage.git


## System Configuration

- **Client Hosts**: 2 EC2 instances (c5n.9xlarge)
- **Server Hosts**: 2 EC2 instances (i3en.12xlarge)
- **Accelerators**: NVIDIA H100 GPUs, up to 128 total (varies by system_desc_id)
- **Storage Layer**: AWS S3 (object store) mounted via Alluxio 3.6.0 FUSE client

## Alluxio Configuration

- Alluxio version: 3.6.0
- Mount: S3 bucket mounted to Alluxio namespace `/mlperf_data`
- Client: Alluxio FUSE client used on training nodes

## How to Run

### Step 1: Mount Alluxio

Alluxio is mounted on each client using:

```bash
alluxio-fuse mount /mnt/alluxio-fuse

Step 2: Generate test data
mlpstorage training datasize -m resnet50 \
--client-host-memory-in-gb 100 --max-accelerators 15 \
--num-client-hosts 1 --accelerator-type h100 \
--results-dir /home/ubuntu/mlps_results

mlpstorage training datagen --hosts=127.0.0.1 \
--model=resnet50 --exec-type=mpi \
--param dataset.num_files_train=3742 --num-processes=30 \
--results-dir=/home/ubuntu/mlps_results \
--data-dir=/mnt/alluxio/alluxio-fuse/s3/resnet50_3742_499GB

Step 3. Run benchmark test
mlpstorage training run \
--hosts 127.0.0.1 --num-client-hosts 1 \
--client-host-memory-in-gb 100 --num-accelerators 15 \
--accelerator-type H100 --model resnet50  \
--data-dir /mnt/alluxio/alluxio-fuse/s3/resnet50_3742_499GB \
--results-dir /home/ubuntu/mlps_results  \
--param dataset.num_files_train=3742 --allow-run-as-root --oversubscribe 

Step 4: Collect Results
Results are collected from the --results-dir and converted into result_<i>.txt format for submission.

Notes:
No modifications were made to the reference MLPerf code.
This implementation is for closed division submission with reference workload.


 
