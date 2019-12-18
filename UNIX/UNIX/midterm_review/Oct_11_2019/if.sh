#!/bin/bash
#comment

echo "input : "
read x

if (( $x>=80 ))
then
    printf A
elif (( $x>=50&&$x<80 ))
then
    printf B
else
    printf C
fi
