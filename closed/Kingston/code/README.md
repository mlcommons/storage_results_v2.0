# Kingston MLPerf Storage v2.0 Submission Code - Dell_R7525_Gen4

This directory contains the code used for the Kingston MLPerf Storage v2.0 submission.

The submission used the standard MLPerf Storage benchmark framework available at:
https://github.com/mlcommons/storage

## System Configuration

System: Dell_R7525_Gen4

## Storage Devices Tested

- KINGSTONSEDC3000ME15T3BK (15.36TB)
- KINGSTONSEDC3000ME3T8BK (3.84TB)
- KINGSTONSEDC3000ME7T6BK (7.68TB)

## Benchmarks Run

- Training workloads: ResNet-50, 3D U-Net, CosmoFlow
- Checkpointing workloads: LLaMA3 models (8B, 70B, 405B, 1T)
- Accelerator types: A100, H100

All benchmarks were run according to MLPerf Storage v2.0 CLOSED division rules.
