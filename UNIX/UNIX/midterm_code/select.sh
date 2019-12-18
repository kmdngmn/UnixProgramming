#!/bin/bash

PS3="input operator: "

select cmd in pwd ls cal date quit
do
    
    case $cmd in
    pwd)
        pwd;;
    ls)
        ls;;
    cal)
        cal;;
    date)
        date;;
    quit)
        break;;
    *)
     echo default
    esac

done
