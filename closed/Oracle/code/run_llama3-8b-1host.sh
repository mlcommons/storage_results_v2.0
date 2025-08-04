export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/
NOW="$(date '+%Y-%m-%d-%H:%M:%S')"

rm -rf /mnt/lustrefs/llama3-8b-1node
sleep 5
sudo sh -c /mnt/lustrefs/storage/drop_caches.sh | tee -a ${NOW}-Caches-droppd-for_llama-3-8b.log
sleep 5
mkdir /mnt/lustrefs/llama3-8b-1node 
sleep 5
mlpstorage checkpointing run --hosts 172.16.4.71 --model llama3-8b --client-host-memory-in-gb 512 --num-processes 8 --checkpoint-folder /mnt/lustrefs/llama3-8b-1node --results-dir /mnt/lustrefs/storage/checkpointing/llama3-8b-1node/ --num-checkpoints-read 0 --num-checkpoints-write 10 --allow-run-as-root --closed

NOW="$(date '+%Y-%m-%d-%H:%M:%S')"

sleep 10
sudo sh -c /mnt/lustrefs/storage/drop_caches.sh | tee -a ${NOW}-Caches-droppd-for_llama-3-8b.log
sleep 10

mlpstorage checkpointing run --hosts 172.16.4.71 --model llama3-8b --client-host-memory-in-gb 512 --num-processes 8 --checkpoint-folder /mnt/lustrefs/llama3-8b-1node --results-dir /mnt/lustrefs/storage/checkpointing/llama3-8b-1node/ --num-checkpoints-read 10 --num-checkpoints-write 0 --allow-run-as-root --closed
