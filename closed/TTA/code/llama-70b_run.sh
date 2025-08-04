#!/bin/bash
echo "======================================="
echo "Checkpoint WRITE"
echo "======================================="
  
  mlpstorage checkpointing run \
    --client-host-memory-in-gb 1024 \
    --model llama3-70b \
    --hosts mlpstorage-driver1:21 mlpstorage-driver2:21 mlpstorage-driver3:22 \
    --num-processes 64 \
    --checkpoint-folder /mnt/checkpoint_test \
    --results-dir ./results_checkpoint_test \
    --num-checkpoints-read=0

echo "======================================="
echo "Clear Caches"
echo "======================================="

  mpirun -hosts mlpstorage-driver1,mlpstorage-driver2,mlpstorage-driver3 \
    -np 3 \
    --bind-to none \
    --map-by ppr:1:node \
    bash -c "echo 3 | sudo tee /proc/sys/vm/drop_caches"

echo "======================================="
echo "Checkpoint READ"
echo "======================================="

  mlpstorage checkpointing run \
    --client-host-memory-in-gb 1024 \
    --model llama3-70b \
    --hosts mlpstorage-driver1:21 mlpstorage-driver2:21 mlpstorage-driver3:22 \
    --num-processes 64 \
    --checkpoint-folder /mnt/checkpoint_test \
    --results-dir ./results_checkpoint_test \
    --num-checkpoints-write=0

echo "======================================="
echo "completed successfully."
echo "======================================="
