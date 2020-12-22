#!/bin/bash
while [ 1 -gt 0 ]
do
	echo "Enter a Number:"
	read a
	rev=0
	sd=0
	or=$a
	total=0
	while [ $a -gt 0 ]
	do
		sd=`expr $a % 10`
		total=`expr $total + $sd`
		temp=`expr $rev \* 10`
		rev=`expr $temp + $sd`
		a=`expr $a / 10`
	done
	echo "Reverse of $or is $rev"
	echo "total of digits is $total"
done

