#!/bin/bash
source=""int" "long" "float" "double" "point""
for i in $source;
    do
    for j in `seq 1 10`;
        do
            size=$(($j * 100000))
            ./hw1 $size $i run
        done
    done