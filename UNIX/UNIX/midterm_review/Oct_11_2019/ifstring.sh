#!/bin/bash

echo "How are you today??"

read x

if [[ $x = [Yy]* ]]
then
    printf "have a nice day~\n"
else
    printf "that's too bad...\n"
fi

