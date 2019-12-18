#!/bin/bash

front=2

while (( front <= 9 ))
do
    back=1
    while(( back <= 9 ))
    do
        let result=front*back

        printf "$result " 
        (( back++ ))

    done
    printf "\n"
    (( front++ ))  
done

exit 0
