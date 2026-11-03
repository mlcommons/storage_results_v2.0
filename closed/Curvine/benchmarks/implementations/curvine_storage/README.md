# Curvine FUSE implementation

## Overview

Curvine v0.2.0 (commit `77320b86`) is a distributed file system. Every DLIO client host mounts the
Curvine namespace with the Curvine FUSE 3 client at `/curvine-fuse`; the benchmark datasets live under
that mount. The underlying file system (UFS) is OpenDAL-S3; the data tier is the local NVMe of the AWS
`i3en.12xlarge` worker nodes. The Curvine master runs on one of the worker nodes.

The benchmark harness is the unmodified MLCommons Storage v2.0 reference code
(`storage.git`, tag `v2.0`, commit `7e71ca1`). DLIO simulates the H100 accelerators; no physical GPU
is used.

## System configuration

- Clients: AWS EC2 `c5n.9xlarge` (36 vCPU, 96 GiB, 50 Gbps ENA). CPU, core count and memory are taken
  from the run artifacts (`summary.json`: Xeon Platinum 8124M, 18 cores / 36 threads, 91.78 GiB available)
- Worker nodes: AWS EC2 `i3en.12xlarge` (48 vCPU, 384 GiB, 4 x 7.5 TB NVMe, 50 Gbps ENA). In this round
  the Curvine worker service was limited to 16 vCPU / 123 GiB per node
- Master: co-located on one worker node
- Mount point: `/curvine-fuse`
- OS release, kernel and MPI version in `systems/<system_id>.yaml` are the values declared at test time;
  they were not captured from the run hosts. The MPI launch flags are recorded per run in
  `training_*_metadata.json`: `--oversubscribe` for every run, plus `--allow-run-as-root` for the
  cosmoflow and 8c runs

## Non-default Curvine configuration

The following values were set in `curvine-cluster.toml` on every mounting client host before the
measured runs; they differ from the packaged defaults.

```toml
[client]
read_chunk_size = "1m"
read_chunk_num = 16
storage_type = "MEM"

[fuse]
direct_io = true
enable_meta_cache = true
meta_cache_timeout = "24h"
node_cache_ttl = "24h"
attr_timeout_ms = 86400000
entry_timeout_ms = 86400000
max_readahead_kb = 1024
```

- `direct_io` bypasses the host page cache for file data, so the measured reads are served by Curvine
  and not by the client page cache.
- `enable_meta_cache`, `meta_cache_timeout`, `node_cache_ttl`, `attr_timeout_ms` and
  `entry_timeout_ms` affect metadata lookups only, never file data.
- `[client] storage_type` is the write placement policy requested at file creation and does not
  affect the read path.
- The worker NVMe devices are the data tier of the storage system itself, not a client-side cache.
  The submitted datasets are 499 GB (1c), 999 GB (2c) and 3999 GB (8c); the aggregate worker memory
  tier is 246 GiB (1c, 2c) and 984 GiB (8c), so a dataset cannot be held resident in memory.
- `read_chunk_size` and `read_chunk_num` set the read chunk size and the number of chunks per slice,
  which is also the default read-ahead length.
- The datasets are 5.45x the total client memory in every submitted configuration.

## Dataset generation

Datagen is executed once per dataset, before the five measured runs. Example (1c resnet50):

```bash
mlpstorage training datagen \
  --hosts 127.0.0.1 \
  --model resnet50 --exec-type mpi --num-processes 30 \
  --param dataset.num_files_train=3742 \
  --data-dir /curvine-fuse/resnet50_3742_499GB \
  --results-dir /home/ec2-user/mlps_results
```

Datagen host/process counts per system and model:

| System | Model | Hosts | Processes | num_files_train | Data dir |
|---|---|---|---|---|---|
| 1c | resnet50 | 1 | 30 | 3742 | /curvine-fuse/resnet50_3742_499GB |
| 1c | unet3d | 1 | 30 | 3662 | /curvine-fuse/unet3d_3662_499GB |
| 1c | cosmoflow | 2 | 64 | 189808 (19 subfolders) | /curvine-fuse/cosmoflow_189808_500GB |
| 2c | resnet50 | 1 | 30 | 7485 | /curvine-fuse/resnet50_7485_999GB |
| 2c | unet3d | 1 | 30 | 7324 | /curvine-fuse/unet3d_7324_999GB |
| 2c | cosmoflow | 2 | 64 | 379617 (38 subfolders) | /curvine-fuse/cosmoflow_379617_1000GB |
| 8c | resnet50 | 8 | 240 | 29942 | /curvine-fuse/resnet50_29942_3999GB |
| 8c | unet3d | 8 | 128 | 29304 | /curvine-fuse/unet3d_29304_3999GB |

## Measured runs

Five consecutive training runs are executed per configuration. The exact `mlpstorage training run`
command for each system and model is stored next to this file as
`benchmarks/<model>/<system_id>/<system_id>_curvine_storage.json` under `run_command`.

## Notes

- One datagen directory and five run directories are submitted per model and system.
- Two cosmoflow datagen stderr logs exceed GitHub's 100 MB file limit and are stored as
  `training_datagen.stderr.log.gz` (complete content, gzip-compressed only).
- `--allow-run-as-root` was passed for the cosmoflow configurations and for the 8c runs. It was not
  passed for the 1c and 2c resnet50 and unet3d configurations.
- The 8c results come from the batch executed on 2026-09-03. An earlier 8c batch
  (2026-08-31 / 2026-09-01) was not submitted.
