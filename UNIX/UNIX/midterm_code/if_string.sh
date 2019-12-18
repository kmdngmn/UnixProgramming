#!/bin/bash

echo input x:
read str

if [[ $str = [Yy]* ]]
then
    echo "yes~"
elif [[ $str = [Nn]* ]]
then
    echo "no~"
else
    echo "else ~"
fi
