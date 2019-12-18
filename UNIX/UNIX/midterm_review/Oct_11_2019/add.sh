#!/bin/bash

function add {
    
    typeset sum
    (( sum= $1+$2 ))

    return $sum

}

add $1 $2
echo $1 + $2 = $?
