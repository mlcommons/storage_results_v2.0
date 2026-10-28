# Curvine — MLPerf Storage v2.0 closed submission

- Submitter: Curvine
- Division: Closed
- Benchmark: Storage v2.0 training (resnet50, unet3d, cosmoflow)
- Benchmark harness: MLCommons `storage.git` tag `v2.0` (commit `7e71ca1`)
- Storage system: Curvine v0.2.0 (commit `77320b86`), FUSE 3 client mounted at `/curvine-fuse`,
  OpenDAL-S3 as the underlying file system (UFS)
- Accelerators: NVIDIA H100 simulated by DLIO (no physical GPU)

## Systems

The accelerator count is model specific; the values below are the number of simulated H100
accelerators (DLIO MPI ranks) used for each model in `results/`.

| System ID | Clients | Worker nodes | resnet50 | unet3d | cosmoflow |
|---|---|---|---|---|---|
| `curvine_c5n9xlarge_fuse_1c_2s_16h` | 1 x c5n.9xlarge | 2 x i3en.12xlarge | 16 | 1 | 5 |
| `curvine_c5n9xlarge_fuse_2c_2s_32h` | 2 x c5n.9xlarge | 2 x i3en.12xlarge | 32 | 2 | 8 |
| `curvine_c5n9xlarge_fuse_8c_8s_128h` | 8 x c5n.9xlarge | 8 x i3en.12xlarge | 128 | 8 | not run |

The Curvine master service is co-located on a worker node. In this round the Curvine worker
service was limited to 16 vCPU / 123 GiB per worker node, whereas the full `i3en.12xlarge`
instance provides 48 vCPU / 384 GiB; this is the main difference to the Alluxio reference
configuration. The 1c/2c/8c system IDs follow the test-plan naming and keep the `2s`/`8s`
worker counts.

System descriptions: `systems/<system_id>.yaml` and `systems/<system_id>.pdf`.

## Results

Five consecutive runs per configuration. Values below are the mean over the five runs; all
configurations meet the closed-division accelerator-utilization expectations.

| System | Model | Mean AU (%) | Mean I/O (MB/s) | Mean throughput (samples/s) |
|---|---|---|---|---|
| 1c | resnet50 | 99.59 | 3102.3 | 28371.1 |
| 1c | unet3d | 99.13 | 2994.3 | 21.42 |
| 1c | cosmoflow | 74.74 | 2813.1 | 1042.9 |
| 2c | resnet50 | 99.24 | 6183.8 | 56551.6 |
| 2c | unet3d | 98.51 | 5951.3 | 42.57 |
| 2c | cosmoflow | 74.60 | 4498.1 | 1667.5 |
| 8c | resnet50 | 97.27 | 24240.4 | 221680.2 |
| 8c | unet3d | 97.69 | 23608.8 | 168.86 |

Per-run metrics are in `results/<system_id>/training/<model>/run/<timestamp>/summary.json`. The final
summary report for each system is `results/<system_id>/results.json`, with `results.csv` as the flat
equivalent. They were produced with the official v2.0 command:

```bash
mlpstorage reports reportgen --results-dir results/<system_id>
```

In v2.0 this command writes `results.json` and `results.csv`; the `mlperf_storage_report.json` name
used in older submission guidelines (and the `benchmark.sh` wrapper it refers to) no longer exists.
`reportgen` reported every run as `CLOSED` with no issues.

## Layout

```
Curvine/
├── benchmarks/
│   ├── <model>/<system_id>/<system_id>_curvine_storage.json
│   └── implementations/curvine_storage/README.md
├── code/
│   ├── README.md
│   └── storage/                  # MLCommons storage.git v2.0, unmodified
├── results/
│   └── <system_id>/{results.json,results.csv,training/<model>/{datagen,run}}
├── systems/
│   └── <system_id>.{yaml,pdf}
└── README.md
```

Each `run/<timestamp>` directory contains the DLIO stdout/stderr logs, `dlio.log`, the resolved
`dlio_config/`, the MLPerf metadata JSON, per-rank outputs and `summary.json`.

## Notes

- The 8c configuration uses the 2026-09-03 batch of five runs. An earlier 8c batch from
  2026-08-31 / 2026-09-01 was excluded.
- Datagen was executed once per dataset, before the measured runs.
- Two cosmoflow datagen stderr logs exceeded GitHub's 100 MB file limit. They are submitted
  gzip-compressed as `training_datagen.stderr.log.gz`; the full, unmodified log content is preserved.
- `--allow-run-as-root` was used for the cosmoflow runs and for all 8c runs. It was not used for the
  1c and 2c resnet50 (16 and 32 ranks) and unet3d (1 and 2 ranks) runs.
- AWS does not publish per-instance power data, so power fields in the system descriptions are `N/A`.
- Curvine build under test: v0.2.0, commit `77320b86`, x86_64 rocky9 package, FUSE3 client with
  `opendal-s3` as the backing UFS.
- Non-default Curvine client and FUSE settings used for the measured runs are listed in
  `benchmarks/implementations/curvine_storage/README.md`. The generated dataset is 5.45x the total
  client memory for every submitted configuration, which satisfies the closed-division caching rule
  on dataset-to-memory ratio.
- System topology, hardware and OS details are in `systems/<system_id>.yaml` and
  `systems/<system_id>.pdf`; the PDF is generated from the YAML and carries the submission date.
- The OS release, kernel and MPI version in the system descriptions are the values declared at test
  time; the run artifacts did not capture them. CPU, core count, memory and the MPI launch flags are
  taken from the run artifacts (`summary.json`, `training_*_metadata.json`).
