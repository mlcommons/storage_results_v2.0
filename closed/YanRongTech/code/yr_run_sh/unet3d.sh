mlpstorage training datasize --model unet3d --client-host-memory-in-gb 1024 --num-client-hosts 8 --max-accelerators 180 --accelerator-type h100 --results-dir=/home/user/mlperf_results/

mlpstorage training datagen --hosts=192.168.255.65,192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70 --model=unet3d --exec-type=mpi --param dataset.num_files_train=630000 --param dataset.num_subfolders_train=63 --num-processes=384 --results-dir=/home/user/mlperf_results/ --data-dir=/mnt/yrfs/mlperf_training_data --allow-run-as-root

for i in {0..7} ;
do
    mlpstorage training run --hosts 192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70,192.168.255.74,192.168.255.75,192.168.255.76 --num-client-hosts 8 --client-host-memory-in-gb 251 --num-accelerators 176 --accelerator-type h100 --model unet3d  --data-dir /mnt/yrfs/mlperf_training_data --results-dir /home/user/mlperf_results --param dataset.num_files_train=616000 dataset.num_subfolders_train=63 --allow-run-as-root --param reader.read_threads=16 --closed --param reader.odirect=true --param dataset.num_subfolders_train=63；
done

sleep 60

for i in {0..7};
do
    mlpstorage training run --hosts 192.168.255.74 --num-client-hosts 1 --client-host-memory-in-gb 251 --num-accelerators 30 --accelerator-type h100 --model unet3d  --data-dir /mnt/yrfs/mlperf_training_data --results-dir /home/user/mlperf_results --param dataset.num_files_train=105000 --param dataset.num_subfolders_train=63 --allow-run-as-root --param reader.read_threads=16 --closed --param reader.odirect=true --param dataset.num_subfolders_train=63；
done
