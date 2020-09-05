#!/bin/bash
for name in bolzano single_case1 single_case2 single_case3
do
    ./run log $name normal theta 2
done    
    




# ./run query combine10 normal theta 2
# ./run query combine100 normal theta 2
# ./run query combine1000 normal theta 2
# ./run query combine10000 normal theta 2
# ./run query concatnate10 normal theta 2
# ./run query concatnate100 normal theta 2
# ./run query concatnate1000 normal theta 2
# ./run query concatnate10000 normal theta 2