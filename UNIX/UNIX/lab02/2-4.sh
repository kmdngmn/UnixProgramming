#!/bin/bash

let sum=$1+$2
let sub=$1-$2
let mul=$1*$2
let div=$1/$2

echo "$1 + $2 = $sum"
echo "$1 - $2 = $sub"
echo "$1 x $2 = $mul"
echo "$1 / $2 = $div"

exit 0
