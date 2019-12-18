#!/bin/bash

select x in pwd cd cal quit
do
    
    case $x in
    pwd)
        pwd;;
    cd)
        cd;;
    cal)
        cal;;
    quit)
        break;;
    *)
    echo "default"
    esac
    
done
