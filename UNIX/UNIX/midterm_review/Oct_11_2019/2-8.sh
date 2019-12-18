#!/bin/bash

echo "is this morning??"

read x

case $x in
y* | Y*)
    echo "yes, this is morning";;
n* | N*)
    echo "no, this is afternoon";;
    *)
    echo default ;;
esac
