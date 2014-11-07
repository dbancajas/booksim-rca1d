for i in `cat rates`;do sed "s/INJRATE/${i}/g" mesh88_rca1d > x && ./booksim x | grep "average flit latency" | awk '{print $6}';done
