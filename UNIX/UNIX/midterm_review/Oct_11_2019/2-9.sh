#!/bin/bash

sum() {
    
    typeset sum

    let sum=$1+$2

    return $sum

}

sum $1 $2

echo $1 + $2 = $?
