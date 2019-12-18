#!/bin/bash

echo input x :
read x

if (( $x>100 ))
then
    echo x is larger than 100
elif (( $x>50 ))
then
    echo x is larger than 50 and less than 100
else
    echo x is smaller than 50
fi    
    

