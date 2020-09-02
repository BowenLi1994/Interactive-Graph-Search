#!/bin/bash
./sequence baseline concatnate10000 > ./deep_result/deep10000_baseline.result
./sequence ordered concatnate10000 > ./deep_result/deep10000_ordered.result
./sequence outdegree concatnate10000 1 > ./deep_result/deep10000_outdegree1.result
./sequence outdegree concatnate10000 2 > ./deep_result/deep10000_outdegree2.result
./sequence outdegree concatnate10000 3 > ./deep_result/deep10000_outdegree3.result
./sequence outdegree concatnate10000 4 > ./deep_result/deep10000_outdegree4.result
./sequence outdegree concatnate10000 5 > ./deep_result/deep10000_outdegree5.result
./sequence outdegree concatnate10000 6 > ./deep_result/deep10000_outdegree6.result
./sequence outdegree concatnate10000 7 > ./deep_result/deep10000_outdegree7.result
./sequence comprehensive concatnate10000 1 > ./deep_result/deep10000_com.result
