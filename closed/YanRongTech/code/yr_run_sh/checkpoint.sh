for i in {0..4};
do
    mlpstorage checkpointing run --model llama3-8b \
  --hosts 192.168.255.68 \
  --num-processes 8 \
  --num-checkpoints-read 0 \
  --num-checkpoints-write 10 \
  --checkpoint-folder /mnt/yrfs/mlperf_checkpoint_data \
  --results-dir /home/user/mlperf_results \
  --client-host-memory-in-gb 251 \
  --exec-type mpi \
  --closed \
  --allow-run-as-root
    sleep 5
    ssh 192.168.255.84 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.85 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.86 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.68 'echo 3 > /proc/sys/vm/drop_caches'
#   ssh 192.168.255.69 'echo 3 > /proc/sys/vm/drop_caches'
    sleep 5
    mlpstorage checkpointing run --model llama3-8b \
  --hosts 192.168.255.68\
  --num-processes 8 \
  --num-checkpoints-read 10 \
  --num-checkpoints-write 0 \
  --checkpoint-folder /mnt/yrfs/mlperf_checkpoint_data \
  --results-dir /home/user/mlperf_results \
  --client-host-memory-in-gb 251 \
  --exec-type mpi \
  --closed \
  --allow-run-as-root
    sleep 5
done

for i in {0..4};
do
 70B write
    mlpstorage checkpointing run --model llama3-70b \
  --hosts 192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70,192.168.255.74,192.168.255.75,192.168.255.76 \
  --num-processes 64 \
  --num-checkpoints-read 0 \
  --num-checkpoints-write 10 \
  --checkpoint-folder /mnt/yrfs//mlperf_checkpoint \
  --results-dir /home/user/mlperf_results/ \
  --client-host-memory-in-gb 251 \
  --exec-type mpi \
  --closed \
  --allow-run-as-root
    sleep 6 
    ssh 192.168.255.84 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.85 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.86 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.67 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.68 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.69 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.70 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.74 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.75 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.76 'echo 3 > /proc/sys/vm/drop_caches'
    ssh 192.168.255.66 'echo 3 > /proc/sys/vm/drop_caches'
    echo 3 > /proc/sys/vm/drop_cache
    sleep 5
# 70B read
    mlpstorage checkpointing run --model llama3-70b \
  --hosts 192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70,192.168.255.74,192.168.255.75,192.168.255.76 \
  --num-processes 64 \
  --num-checkpoints-read 10 \
  --num-checkpoints-write 0 \
  --checkpoint-folder /mnt/yrfs//mlperf_checkpoint_data \
  --results-dir /home/user/mlperf_results/ \
  --client-host-memory-in-gb 251 \
  --exec-type mpi \
  --closed \
  --allow-run-as-root
    sleep 5
#done
