#!/bin/bash

count=0
while (( count<=2 ))
do
    echo "hello"
    
    let count++

    if (( count==1 ))
    then
        continue
    fi

done
