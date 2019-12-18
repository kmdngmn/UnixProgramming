#!/bin/bash

count=1
sum=0
 
while (( count<=5 ))
do
    
    (( sum+=count ))
    (( count++ ))

done

echo $sum
