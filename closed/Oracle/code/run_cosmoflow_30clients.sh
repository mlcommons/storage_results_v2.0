export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/

mlpstorage training run --hosts=172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4,172.16.7.6,172.16.7.62,172.16.7.63,172.16.7.70,172.16.7.90,172.16.7.96,172.16.7.159,172.16.7.167 --num-client-hosts 30 --model=cosmoflow --exec-type=mpi --accelerator h100 --num-accelerators 120 --param dataset.num_files_train=31200000 dataset.num_subfolders_train=3120 reader.prefetch_size=32 reader.read_threads=32 reader.transfer_size=1048576 reader.computation_threads=4 --results-dir=./Closed/Oracle/results/cosmoflow --data-dir=/mnt/lustrefs/cosmoflow32N --client-host-memory-in-gb 512 --closed

sleep 20

#clush -w cmp-[72,104,146,159,174,205,230,270,351,366,383,435,462,473,489,551,591,658,710,734,749,773,775,831-832,839,859,865,928,936,938,999] sudo /mnt/lustrefs/drop_caches.sh

mlpstorage training run --hosts=172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.6.197,172.16.4.71,172.16.6.221,172.16.6.236,172.16.7.4,172.16.7.6,172.16.7.62,172.16.7.63,172.16.7.70,172.16.7.90,172.16.7.96,172.16.7.159,172.16.7.167 --num-client-hosts 30 --model=cosmoflow --exec-type=mpi --accelerator h100 --num-accelerators 120 --param dataset.num_files_train=31200000 dataset.num_subfolders_train=3120 reader.prefetch_size=32 reader.read_threads=32 reader.transfer_size=1048576 reader.computation_threads=4 --results-dir=./Closed/Oracle/results/cosmoflow --data-dir=/mnt/lustrefs/cosmoflow32N --client-host-memory-in-gb 512 --loops 5 --closed
