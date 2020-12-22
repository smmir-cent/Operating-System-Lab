#!/bin/bash
while [ 1 -gt 0 ]
do
	echo "Enter X:"
	read x
	echo "Enter Y:"
	read y
	echo "Enter file address:"
	read file0
	lines=$(< "$file0" wc -l)
	if [[ $x -gt 0 && $y -lt $lines && $x -lt $y ]] ; then 
	    sed -n "$x,$y""p" $file0
	else 
 	    echo Invalid Inputs
	fi
done

