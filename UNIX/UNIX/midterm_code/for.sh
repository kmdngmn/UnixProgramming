#!/bin/bash

sum=0
for num in 0 1 2 3
do
    (( sum += num ))

done

echo $sum
