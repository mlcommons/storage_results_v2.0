#!/bin/bash
set -e

# Install dependencise
sudo apt update
sudo apt install -y openjdk-11-jdk fuse curl wget

# Install Alluxio）
wget https://downloads.alluxio.io/downloads/files/3.6.0/alluxio-3.6.0-bin.tar.gz
tar -xzf alluxio-3.6.0-bin.tar.gz

