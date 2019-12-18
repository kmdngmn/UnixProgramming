#!/bin/bash

sum() {
    (( sum = $1+$2 ))
    return $sum
}

sum $1 $2

printf "sum is $?\n"

exit
