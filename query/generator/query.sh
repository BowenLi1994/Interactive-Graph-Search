#!/bin/bash
COMMAND=./run


TYPE1=log
TYPE2=query
DISTRIBUTION1=zipf
DISTRIBUTION2=uniform

KIND=theta
THRESHOLD=2

#log-file zipf 2.0
for name in combine100 combine1000 combine10000 
do
    $COMMAND $TYPE1 $name $DISTRIBUTION1 $KIND $THRESHOLD &
done    
    
#query-file zipf 2.0
for name in combine100 combine1000 combine10000 
do
    $COMMAND $TYPE2 $name $DISTRIBUTION1 $KIND $THRESHOLD &
done  

#log-file uniform 2.0
for name in combine100 combine1000 combine10000 
do
    $COMMAND $TYPE1 $name $DISTRIBUTION2 $KIND $THRESHOLD &
done

#query-file uniform 2.0
for name in combine100 combine1000 combine10000 
do
    $COMMAND $TYPE2 $name $DISTRIBUTION2 $KIND $THRESHOLD &
done  



# ./run query combine10 normal theta 2
# ./run query combine100 normal theta 2
# ./run query combine1000 normal theta 2
# ./run query combine10000 normal theta 2
# ./run query concatnate10 normal theta 2
# ./run query concatnate100 normal theta 2
# ./run query concatnate1000 normal theta 2
# ./run query concatnate10000 normal theta 2