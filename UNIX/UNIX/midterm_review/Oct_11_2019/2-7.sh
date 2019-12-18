#!/bin/bash

front=2
while (( front<=9 ))
do
    back=1
    while (( back<=9 ))
    do
        let mul=front*back
        printf "$mul  "
        (( back++ ))
    done
    (( front++ ))
    printf "\n"

done
