#!/bin/bash

echo -n "name : "
read person

until who | grep $person
do
    sleep 3
done

echo "\007"
