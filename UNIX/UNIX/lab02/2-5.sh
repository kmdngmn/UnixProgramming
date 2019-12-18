#!/bin/bash

HOUR=`date +%H`

if (($HOUR <= 12))
then
    printf "Good morning\n" # different with C Language
elif (($HOUR <= 17))
then
    printf "Good afternoon\n"
else
    printf "Good night\n"
fi

exit 0
