#!/bin/bash

sum(){
    ((sum = $1 + $2))
    return $sum
}

#sum $1 $2   $./2-9.sh 30 40  -> The result is 70
sum 10 20
echo The result is $?

exit 0
