#!/bin/bash

for DIR in $(ls ~/UNIX)
do
    if [[ -d ~/UNIX/$DIR ]]
    then
        ls -R ~/UNIX/$DIR
    fi

done
