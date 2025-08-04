#!/bin/bash

NODES=$(sinfo -h -N -o "%n" | sort -u)

INTERFACE="ens300f0np0"

IP_LIST=()

for host in $NODES; do
	echo "Querying host for network $INTERFACE"
	ip=$(ssh -o ConnectTimeout=5 -o StrictHostKeyChecking=no "$host" \
	   "ip -4 addr show dev $INTERFACE | grep 'inet' | awk '{print \$2}' | cut -d/ -f1")
	if [[ -n "$ip" ]]; then
		IP_LIST+=("$ip")
	else
		echo "Failed to get IP from $host" >&2
	fi
done

echo "${IP_LIST[*]}" | tr ' ' ','
