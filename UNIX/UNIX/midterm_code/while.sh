#!/bin/bash

echo input num:
read x
i=1

sum=0

while (( i <= x ))
do
    (( sum+=i ))
    (( i++ ))

done

echo $sum
