export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/

rm -rf /mnt/lustrefs/llama3-405b
sleep 20

clush -w 172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4,172.16.7.6,172.16.7.62,172.16.7.63,172.16.7.70,172.16.7.90,172.16.7.96,172.16.7.159,172.16.7.167,172.16.7.169,172.16.7.230 sudo /mnt/lustrefs/storage/drop_caches.sh

sleep 20
mkdir /mnt/lustrefs/llama3-405b

sudo lfs setdirstripe -c 4 -D /mnt/lustrefs/llama3-405b

mlpstorage checkpointing run --hosts 172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4 --model llama3-405b --client-host-memory-in-gb 512 --num-processes 512 --checkpoint-folder /mnt/lustrefs/llama3-405b --results-dir /mnt/lustrefs/storage/checkpointing/llama3-405b-22node/ --num-checkpoints-read 0 --num-checkpoints-write 10 --allow-run-as-root --closed

sleep 20

clush -w 172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4,172.16.7.6,172.16.7.62,172.16.7.63,172.16.7.70,172.16.7.90,172.16.7.96,172.16.7.159,172.16.7.167,172.16.7.169,172.16.7.230 sudo /mnt/lustrefs/storage/drop_caches.sh

sleep 20


mlpstorage checkpointing run --hosts 172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4 --model llama3-405b --client-host-memory-in-gb 512 --num-processes 512 --checkpoint-folder /mnt/lustrefs/llama3-405b --results-dir /mnt/lustrefs/storage/checkpointing/llama3-405b-22node/ --num-checkpoints-read 10 --num-checkpoints-write 0 --allow-run-as-root --closed
