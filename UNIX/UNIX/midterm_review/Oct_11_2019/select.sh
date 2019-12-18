#!/bin/bash

select s in pwd date cal quit
do
    case $s in
    pwd)
        echo `pwd` ;;
    date)
        date ;;
    cal)
        cal ;;
    quit)
        break ;;
    *)
    echo "default"
    esac

done


