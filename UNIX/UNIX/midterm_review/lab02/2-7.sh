#!/bin/bash

a=2
while (( a<=9 ))
do
    b=1
    while (( b<=9 ))
    do
        printf " "
        let mul=$a*$b
        let b++
        printf $mul
        
    done
    let a++

    printf "\n"

done
