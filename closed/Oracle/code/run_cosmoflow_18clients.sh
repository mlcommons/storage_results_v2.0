export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/

mlpstorage training run --hosts=172.16.4.103,172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.6.78,172.16.6.145,172.16.4.71 --num-client-hosts 18 --model=cosmoflow --exec-type=mpi --accelerator a100 --num-accelerators 90 --param dataset.num_files_train=3279960 reader.read_threads=36 reader.prefetch_size=36 --results-dir=./Oracle/32Nodes-cosmoflow-nosubfolders --data-dir=/mnt/lustrefs/cosmoflownosub/ --client-host-memory-in-gb 96 --closed

sleep 20

#clush -w cmp-[72,104,146,159,174,205,230,270,351,366,383,435,462,473,489,551,591,658,710,734,749,773,775,831-832,839,859,865,928,936,938,999] sudo /mnt/lustrefs/drop_caches.sh

