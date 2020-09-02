#!/bin/bash
./sequence baseline concatnate1000 > ./deep_result/deep1000_baseline.result
./sequence ordered concatnate1000 > ./deep_result/deep1000_ordered.result
./sequence outdegree concatnate1000 1 > ./deep_result/deep1000_outdegree1.result
./sequence outdegree concatnate1000 2 > ./deep_result/deep1000_outdegree2.result
./sequence outdegree concatnate1000 3 > ./deep_result/deep1000_outdegree3.result
./sequence outdegree concatnate1000 4 > ./deep_result/deep1000_outdegree4.result
./sequence outdegree concatnate1000 5 > ./deep_result/deep1000_outdegree5.result
./sequence outdegree concatnate1000 6 > ./deep_result/deep1000_outdegree6.result
./sequence outdegree concatnate1000 7 > ./deep_result/deep1000_outdegree7.result
./sequence comprehensive concatnate1000 1 > ./deep_result/deep1000_com.result
