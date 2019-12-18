#!/bin/bash

select cmd in pwd ls date quit
do
    
    case $cmd in
    pwd)
        echo `pwd` ;;
    ls)
        echo `ls` ;;
    date)
        echo `date` ;;
    quit)
        break ;;
    *)
        echo error
        
    esac    
done

