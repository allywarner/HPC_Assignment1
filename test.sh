#!/bin/bash
source=""int" "long" "float" "double" "coordinate""
for i in $source;
    do
        echo $i
    for j in 'seq 1 10'
        do
            echo $(($j * 1000))
            ./hw1 $j $i test
        done
    done