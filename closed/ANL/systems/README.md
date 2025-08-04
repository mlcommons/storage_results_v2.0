# cgroup to limit the DRAM

Each compute node is equipped with approximately 1 TB of DRAM. To benchmark training workloads such as CosmoFlow, UNet3D, and ResNet50, we limit the available DRAM to 32 GB per node using cgroups.

```bash
cat /sys/fs/cgroup/memory$( grep -Poe "(?<=memory\:).+" /proc/self/cgroup )/memory.limit_in_bytes
cat /sys/fs/cgroup/memory$( grep -Poe "(?<=memory\:).+" /proc/self/cgroup )/memory.soft_limit_in_bytes
```

The following commend confirmed that it was 32GB as we set. 