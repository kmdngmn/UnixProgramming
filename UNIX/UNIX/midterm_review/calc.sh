#!/bin/bash

read x y

echo "x+y=" $((x+y))
echo "x-y=" $((x-y))

echo "x*y=" $((x*y))
echo "x/y=" $((x/y))
echo "shift" $((x << y))
