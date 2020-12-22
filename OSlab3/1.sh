#!/bin/bash
re='^[0-9]+$'
if ! [[ $1 =~ $re ]] ; then
   echo "error: num1 is Not a number"
fi
if ! [[ $2 =~ $re ]] ; then
   echo "error: num2 is Not a number"
fi
if [[ $1 =~ $re && $2 =~ $re ]] ; then
	echo -n "total is "
	bc <<< "scale=4; $1+$2"
	if [[ $1 -gt $2 ]] ; then
		echo "bigger is $1"
	else
		echo "bigger is $2"
	fi
fi
