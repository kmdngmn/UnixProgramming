#!/bin/bash

echo input operator

read cmd

case $cmd in
[0-9])
    date ;;
"cal" | "CAL")
    cal ;;
[aA-C]*)
    pwd ;;
*)
    echo default
    ;;
esac

