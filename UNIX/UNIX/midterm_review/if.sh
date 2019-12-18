#!/bin/bash

read x

if (($x > 100))
then
    echo A
elif (($x > 50))
then
    echo B
else
    echo C
fi

read y

if [[ $y = *[Yyx] ]]
then
    echo y or Y
else
    echo no y
fi
