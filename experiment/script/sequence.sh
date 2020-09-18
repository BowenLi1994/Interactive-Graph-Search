#!/bin/bash
COMMAND=../sequence
METHOD=outdegree
DATASET=concatnate10000
OUT_PATH=/home/bowen/igs_result/deep10000/

for THRESHOLD in  10 20 30 40 50 60 70 80 90 100
do
    $COMMAND $METHOD $DATASET $THRESHOLD > ${OUT_PATH}${DATASET}_${METHOD}${THRESHOLD}.result &
done    
    
