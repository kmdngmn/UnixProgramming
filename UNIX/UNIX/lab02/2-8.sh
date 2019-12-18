#!/bin/bash

echo -n "Is is morning?"
read answer
case $answer in
    y* | Y* ) echo Good morning ;;
    n* | N* ) echo Have a good day ;;
    *) echo Sorry your answer is not proper ;;
esac

exit 0
