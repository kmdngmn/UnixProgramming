#!/bin/bash

typeset sum

for num in 1 2 3 4 5
do
    let sum+=$num
done

echo $sum
