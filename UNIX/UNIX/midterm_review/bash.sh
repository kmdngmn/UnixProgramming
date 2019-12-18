#!/bin/bash

echo insert : 

read x

case $x in
[0-9]*)
    echo digit ;;
[aA-Zz]*)
    echo string ;;
*)
    echo default;

esac    
