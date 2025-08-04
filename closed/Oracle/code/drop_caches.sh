#!/bin/bash

{
	echo "Dropping caches
	sync
	sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'
	echo "Successfully dropped caches
} 2>&1
