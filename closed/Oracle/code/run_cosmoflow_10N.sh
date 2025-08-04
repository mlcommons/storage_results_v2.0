export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/

mlpstorage training run --hosts=172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.6.38,172.16.4.71 --num-client-hosts 10 --model=cosmoflow --exec-type=mpi --accelerator a100 --num-accelerators 40 --param reader.transfer_size=131072 dataset.num_files_train=1830000 dataset.num_subfolders_train=183 reader.read_threads=36 reader.prefetch_size=36 --results-dir=./Oracle/cosmoflow/10N/ --data-dir=/mnt/lustrefs/cosmoflow10N/ --client-host-memory-in-gb 96 --closed

sleep 20

#clush -w cmp-[72,104,146,159,174,205,230,270,351,366,383,435,462,473,489,551,591,658,710,734,749,773,775,831-832,839,859,865,928,936,938,999] sudo /mnt/lustrefs/drop_caches.sh

