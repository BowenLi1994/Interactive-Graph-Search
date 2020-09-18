#!/bin/bash
COMMAND=./run
DISTRIBUTION=zipf
THRESHOLD=2.0

for name in combine100 combine1000
do
    $COMMAND $name ${name}_${DISTRIBUTION}_${THRESHOLD} &
done    
    
DISTRIBUTION1=uniform
for name in combine100 combine1000
do
    $COMMAND $name ${name}_${DISTRIBUTION1}_${THRESHOLD} &
done  