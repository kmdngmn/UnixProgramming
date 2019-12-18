#!/bin/bash

typeset sum
count=0

function sum {

    while (( count<=$1 ))
    do
        let sum+=$count
        let count++

    done

    return $sum

}

sum $1

echo 1~$1 sum is $?

