#!/bin/bash
COMMAND=../random
METHOD1=baseline
METHOD2=ordered
METHOD3=frequency
METHOD4=frequency2

#wide100
DATASET1=combine100
OUT_PATH1=/home/bowen/igs_result/wide100/
TYPE1=combine100_normal_2.0
TYPE2=combine100_zipf_2.0
TYPE3=combine100_uniform_2.0


for METHOD in  $METHOD1 $METHOD2 $METHOD3 $METHOD4
do
    $COMMAND $METHOD $DATASET1 $TYPE1 > ${OUT_PATH1}${DATASET1}_${METHOD}_normal.result &
done

for METHOD in  $METHOD1 $METHOD2 $METHOD3 $METHOD4
do
    $COMMAND $METHOD $DATASET1 $TYPE2 > ${OUT_PATH1}${DATASET1}_${METHOD}_zipf.result &
done

for METHOD in  $METHOD1 $METHOD2 $METHOD3 $METHOD4
do
    $COMMAND $METHOD $DATASET1 $TYPE3 > ${OUT_PATH1}${DATASET1}_${METHOD}_uniform.result &
done   
