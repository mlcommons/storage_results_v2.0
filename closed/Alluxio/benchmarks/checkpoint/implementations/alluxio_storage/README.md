# Checkpoint Benchmark for Alluxio + LLaMA3

This benchmark evaluates checkpoint save/load throughput using Alluxio FUSE for different LLaMA3 models:
- llama3-8b (105GB)
- llama3-70b (114GB / 912GB)
- llama3-405b (94GB / 752GB)
- llama3-1t (161GB / 1288GB)

The datasets are either synthetically generated or prepared from model training output.

## Configuration
- Alluxio FUSE client(s) mounted the S3 storage.
- Tests were run using MLPerf Storage v2.0 benchmark tools (tag v2.0-rc0).

## Notes
- Two configurations were tested: 1 FUSE client and 8 FUSE clients.
- Result files summarize throughput measurements.

