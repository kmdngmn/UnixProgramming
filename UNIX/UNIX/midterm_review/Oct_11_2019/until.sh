#!/bin/bash

typeset sum

count=0

until (( count<=10 ))
do
    let sum+=$count
    (( count++ ))

done

echo $sum
