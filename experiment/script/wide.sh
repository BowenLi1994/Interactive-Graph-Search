#!/bin/bash

COMMAND=../sequence
METHOD1=outdegree
METHOD2=baseline
METHOD3=comprehensive
METHOD4=compared

DATASET=combine100
OUT_PATH=/home/bowen/igs_result/wide100/

$COMMAND $METHOD2 $DATASET > ${OUT_PATH}${DATASET}_${METHOD2}.result &
$COMMAND $METHOD3 $DATASET 1 > ${OUT_PATH}${DATASET}_${METHOD3}.result &
$COMMAND $METHOD4 $DATASET > ${OUT_PATH}${DATASET}_${METHOD4}.result &

for THRESHOLD in  100 200 300 400 500 600 700 800 900 1000
do
    $COMMAND $METHOD1 $DATASET $THRESHOLD > ${OUT_PATH}${DATASET}_${METHOD1}${THRESHOLD}.result &
done    
    
