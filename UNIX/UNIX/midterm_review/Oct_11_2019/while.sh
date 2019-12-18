#!/bin/bash

typeset sum
count=0

while (( count<=100 ))
do

    let sum+=$count
    (( count++ ))

done

echo $sum
