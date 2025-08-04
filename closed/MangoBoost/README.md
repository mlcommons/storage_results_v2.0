# MLPerf Storage 2.0

To run our SUT, please first refer to the system setup instruction provided in the PDFs of the /system directory.

The following steps outline the process of setting up the initiator and target sides on the storage system to reproduce our MLPerf Storage V2.0 results.

---

## 1. On the target

First, ensure that the devices are available.

Run the following command (with updated IP and device information depending on the SUT) to setup NVMe/TCP Target.

```bash
sudo mango-ctl dev enable 0000:99:00.0 toe
sudo mango-ctl dev enable 0000:9a:00.0 toe
sudo mango-ctl dev enable 0000:ab:00.0 toe
sudo mango-ctl dev enable 0000:ac:00.0 toe

sudo ifconfig ens1 107.22.1.101/24 up
sudo ifconfig enp154s0 107.22.2.101/24 up
sudo ifconfig enp171s0 107.22.3.101/24 up
sudo ifconfig enp172s0 107.22.4.101/24 up

sudo mango-ctl nvmf start \
  --trtype TCP \
  --device-list 0,1,2,3

sudo mango-ctl nvmf attach_nvme 0000:bf:00.0 -b Nvme0
sudo mango-ctl nvmf attach_nvme 0000:c0:00.0 -b Nvme1
sudo mango-ctl nvmf attach_nvme 0000:cf:00.0 -b Nvme2
sudo mango-ctl nvmf attach_nvme 0000:d0:00.0 -b Nvme3
sudo mango-ctl nvmf attach_nvme 0000:e1:00.0 -b Nvme4
sudo mango-ctl nvmf attach_nvme 0000:e2:00.0 -b Nvme5
sudo mango-ctl nvmf attach_nvme 0000:e3:00.0 -b Nvme6
sudo mango-ctl nvmf attach_nvme 0000:e4:00.0 -b Nvme7

sudo mango-ctl nvmf create_subsys -n nqn.2025-06.io.spdk:eval4_cnode0 --allow_any 1
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode0 -b Nvme0
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode0 -b Nvme1

sudo mango-ctl nvmf create_subsys -n nqn.2025-06.io.spdk:eval4_cnode1 --allow_any 1
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode1 -b Nvme2
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode1 -b Nvme3

sudo mango-ctl nvmf create_subsys -n nqn.2025-06.io.spdk:eval4_cnode2 --allow_any 1
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode2 -b Nvme4
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode2 -b Nvme5

sudo mango-ctl nvmf create_subsys -n nqn.2025-06.io.spdk:eval4_cnode3 --allow_any 1
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode3 -b Nvme6
sudo mango-ctl nvmf add_ns -n nqn.2025-06.io.spdk:eval4_cnode3 -b Nvme7

sudo mango-ctl nvmf add_listener -n nqn.2025-06.io.spdk:eval4_cnode0 -a 107.22.1.101
sudo mango-ctl nvmf add_listener -n nqn.2025-06.io.spdk:eval4_cnode1 -a 107.22.2.101
sudo mango-ctl nvmf add_listener -n nqn.2025-06.io.spdk:eval4_cnode2 -a 107.22.3.101
sudo mango-ctl nvmf add_listener -n nqn.2025-06.io.spdk:eval4_cnode3 -a 107.22.4.101
```

## 2. Running the Initiator

Again, ensure that the devices are available.

Setup the configurations based using the following information (with updated IP and device information depending on the SUT) to setup NVMe/TCP Initiator and connect to the NVMe/TCP Target.


On config_1.json:

```bash
{
  "soc ethernet": {
    "port_0": {
      "address": "107.22.1.111/24"
    },
    "port_1": {
      "address": "107.22.2.111/24"
    }
  },
  "targets": {
    "PF0": {
      "subnqn": "nqn.2025-06.io.spdk:eval4_cnode0",
      "type": "nvmf",
      "devname": "Nvme0",
      "traddr": ["107.22.1.101"],
      "trsvcid": ["4420"],
      "trtype": ["TCP"],
      "VF": []
    },
    "PF1": {
      "subnqn": "nqn.2025-06.io.spdk:eval4_cnode1",
      "type": "nvmf",
      "devname": "Nvme1",
      "traddr": ["107.22.2.101"],
      "trsvcid": ["4420"],
      "trtype": ["TCP"],
      "VF": []
    }
  }
}
```

On config_2.json:

```bash
{
  "soc ethernet": {
    "port_0": {
      "address": "107.22.3.111/24"
    },
    "port_1": {
      "address": "107.22.4.111/24"
    }
  },
  "targets": {
    "PF0": {
      "subnqn": "nqn.2025-06.io.spdk:eval4_cnode2",
      "type": "nvmf",
      "devname": "Nvme2",
      "traddr": ["107.22.3.101"],
      "trsvcid": ["4420"],
      "trtype": ["TCP"],
      "VF": []
    },
    "PF1": {
      "subnqn": "nqn.2025-06.io.spdk:eval4_cnode3",
      "type": "nvmf",
      "devname": "Nvme3",
      "traddr": ["107.22.4.101"],
      "trsvcid": ["4420"],
      "trtype": ["TCP"],
      "VF": []
    }
  }
}
```

Then, run the following command (similar to other steps, please make sure the device and IPs are correct depending on your SUT):

```bash
sudo mango-ctl soc push config_1.json 0000:e1:00.1
sudo mango-ctl soc push config_2.json 0000:92:00.1

sudo mango-ctl soc service start mango-nti 0000:92:00.1
sudo mango-ctl soc service start mango-nti 0000:e1:00.1

echo 0000:91:00.0 | sudo tee /sys/bus/pci/drivers/nvme/bind
echo 0000:92:00.0 | sudo tee /sys/bus/pci/drivers/nvme/bind
echo 0000:e1:00.0 | sudo tee /sys/bus/pci/drivers/nvme/bind
echo 0000:e2:00.0 | sudo tee /sys/bus/pci/drivers/nvme/bind

sudo nvme list
...
Node                  SN                   Model                                    Namespace Usage                      Format           FW Rev
--------------------- -------------------- ---------------------------------------- --------- -------------------------- ---------------- --------
/dev/nvme0n1          MB_TOE_Nvme1         MangoBoost NVMe Virtual Device           1           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme0n2          MB_TOE_Nvme1         MangoBoost NVMe Virtual Device           2           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme1n1          MB_TOE_Nvme0         MangoBoost NVMe Virtual Device           1           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme1n2          MB_TOE_Nvme0         MangoBoost NVMe Virtual Device           2           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme2n1          MB_TOE_Nvme2         MangoBoost NVMe Virtual Device           1           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme2n2          MB_TOE_Nvme2         MangoBoost NVMe Virtual Device           2           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme3n1          MB_TOE_Nvme3         MangoBoost NVMe Virtual Device           1           3.20  TB /   3.20  TB    512   B +  0 B   23.09
/dev/nvme3n2          MB_TOE_Nvme3         MangoBoost NVMe Virtual Device           2           3.20  TB /   3.20  TB    512   B +  0 B   23.09
```
