mlpstorage training datagen --hosts=127.0.0.1 --model=cosmoflow --exec-type=mpi --param dataset.num_files_train=4800000 --num-processes=64 --results-dir=/home/user/mlperf_results/ --data-dir=/mnt/yrfs/mlperf_training_data --allow-run-as-root

for i in {0..14} ;
do
    mlpstorage training run --hosts  192.168.255.74   --num-client-hosts 1 --client-host-memory-in-gb 251 --num-accelerators 60 --accelerator-type h100 --model cosmoflow --data-dir /mnt/yrfs/mlperf_training_data --results-dir /home/user/mlperf_results --param dataset.num_files_train=480000 --param dataset.num_subfolders_train=600 --allow-run-as-root --closed --param reader.read_threads=1 --param reader.computation_threads=1 --param reader.transfer_size=2900992
done

for i in {0..14} ;
do
    mlpstorage training run  --hosts 192.168.255.65,192.168.255.66,192.168.255.67,192.168.255.68,192.168.255.69,192.168.255.70,192.168.255.74,192.168.255.75,192.168.255.76 --num-client-hosts 9  --client-host-memory-in-gb 251 --num-accelerators 243  --accelerator-type h100  --model cosmoflow --data-dir /mnt/yrfs/mlperf_training_data --results-dir /home/user/mlperf_results --param dataset.num_files_train=2858517 --allow-run-as-root --closed --param reader.read_threads=1 --param reader.computation_threads=1 --param reader.transfer_size=2858517
done

