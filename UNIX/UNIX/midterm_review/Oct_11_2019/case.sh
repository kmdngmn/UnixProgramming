#!/bin/bash

echo "input operation"

read x

case $x in
"pwd")
   pwd;;
"cal")
   cal;;
"date")
   date;;
*)
   echo "default\n"
esac
