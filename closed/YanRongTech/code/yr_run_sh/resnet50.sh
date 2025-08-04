mlpstorage training datasize --model resnet50 --client-host-memory-in-gb 251 --num-client-hosts 9 --max-accelerators 1620 --accelerator-type h100 --results-dir=/home/user/mlperf_results/
mlpstorage training datagen --hosts=127.0.0.1 --model=resnet50 --exec-type=mpi --param dataset.num_files_train=258992 --num-processes=64 --results-dir=/home/user/mlperf_results/ --data-dir=/mnt/yrfs/mlperf_training_data --allow-run-as-root

for i in {0..6} ;
do
	mlpstorage training run --hosts 192.168.255.65,192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70,192.168.255.74,192.168.255.75,192.168.255.76 --num-client-hosts 9  --client-host-memory-in-gb 251  --num-accelerators 1404 --accelerator-type h100  --model resnet50 --data-dir /mnt/yrfs/mlperf_training_data --results-dir /home/user/mlperf_results --param dataset.num_files_train=224460 --allow-run-as-root --closed --param reader.read_threads=2 --param dataset.num_subfolders_train=26；
done
