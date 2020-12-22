#!/bin/bash
function func1 {
    for i in 1 2 3 4 5
        do
	for (( c=1; c<=$i; c++ ))
            do  
            echo -n "$i" 
        done
	echo
    done
}
function func2 {
    MAX=6
    for (( i=1; i<=MAX; i++ ))
    do
        for (( s=MAX; s>=i; s-- ))
        do
            echo -n " "
        done
        for (( j=1; j<=i;  j++ ))
        do
            echo -n " *"
        done
        echo 
    done

    for (( i=MAX; i>=1; i-- ))
    do
        for (( s=i; s<=MAX; s++ ))
        do
            echo -n " "
        done
        for (( j=1; j<=i;  j++ ))
        do
            echo -n " *"
        done
        echo
    done
}
function func3 {
    for i in 1 2 3 4 5
        do
	for (( c=1; c<$i; c++ ))
            do  
            echo -n "| " 
        done
	echo "|_"
    done
}

while [ 1 -gt 0 ]
do
	echo "Enter a Number(1,2,3):"
	read a
	if [[ $a -eq 1 ]] ; then
		func1
	elif [[ $a -eq 2 ]] ; then
		func2
	elif [[ $a -eq 3 ]] ; then
		func3
	else
		echo "WRONG NUMBER"
	fi

done
