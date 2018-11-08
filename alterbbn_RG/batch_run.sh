#!/usr/bin/bash
filename=/scratch/rag394/alterbbn/09_03_2018.dat

rm $filename
for As in $(seq 0.00 0.01 3.0); do
    echo $As
    ./vary_x.x ${As}e14 0. 0. 0. 0. 0. 0. 0 >> $filename
done
