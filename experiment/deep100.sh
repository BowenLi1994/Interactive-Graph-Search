#!/bin/bash
./sequence baseline concatnate100 > ./deep_result/deep100_baseline.result
./sequence ordered concatnate100 > ./deep_result/deep100_ordered.result
./sequence outdegree concatnate100 1 > ./deep_result/deep100_outdegree1.result
./sequence outdegree concatnate100 2 > ./deep_result/deep100_outdegree2.result
./sequence outdegree concatnate100 3 > ./deep_result/deep100_outdegree3.result
./sequence outdegree concatnate100 4 > ./deep_result/deep100_outdegree4.result
./sequence outdegree concatnate100 5 > ./deep_result/deep100_outdegree5.result
./sequence outdegree concatnate100 6 > ./deep_result/deep100_outdegree6.result
./sequence outdegree concatnate100 7 > ./deep_result/deep100_outdegree7.result
./sequence comprehensive concatnate100 1 > ./deep_result/deep100_com.result
