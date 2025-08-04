export OMPI_MCA_btl=self,tcp
export OMPI_MCA_btl_tcp_if_include=ens300f0np0
export OMPI_MCA_pml=ob1
export PATH=$PATH:/home/ubuntu/.local/bin/

mlpstorage training run --hosts=172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.4.71,172.16.6.221 --num-client-hosts 15 --model=unet3d --exec-type=mpi --accelerator a100 --num-accelerators 45 --param dataset.num_files_train=281295 reader.read_threads=36 --results-dir=./Closed/Oracle/results/15Node-3PPN-unet3d/ --data-dir=/mnt/lustrefs/unet3d15N --client-host-memory-in-gb 512 --closed

sleep 30

mlpstorage training run --hosts=172.16.4.145,172.16.4.158,172.16.4.173,172.16.4.204,172.16.4.229,172.16.5.13,172.16.5.94,172.16.5.109,172.16.5.126,172.16.5.178,172.16.5.205,172.16.5.216,172.16.5.232,172.16.4.71,172.16.6.221 --num-client-hosts 15 --model=unet3d --exec-type=mpi --accelerator a100 --num-accelerators 45 --param dataset.num_files_train=281295 reader.read_threads=36 --results-dir=./Closed/Oracle/results/15Node-3PPN-unet3d/ --data-dir=/mnt/lustrefs/unet3d15N --client-host-memory-in-gb 512 --loops 5 --closed



