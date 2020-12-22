#!/bin/bash
if [[ $# -eq 0 ]] ; then
    while true
    do
        
        echo 1. Addition
        echo 2. Subtraction
        echo 3. Multiplication
        echo 4. Division
        echo 5. Exit
        echo Enter your choice:
        read choice
        if [[ $choice -eq 5 ]] ; then
            exit
	fi
        echo Enter operand1 value:
        read operand1
        echo Enter operand2 value:
        read operand2
        if [[ $choice -eq 1 ]] ; then
            #echo Enter operand1 value:
            #read operand1
            #echo Enter operand2 value:
            #read operand2
	    answer=$(bc <<< "scale=4; $operand1+$operand2")
            echo ----------------------------------------
            echo Addition of $operand1 and $operand2 is $answer
            echo ----------------------------------------
            echo
        elif [[ $choice -eq 2 ]] ; then
            #echo Enter operand1 value:
            #read operand1
            #echo Enter operand2 value:
            #read operand2
	    answer=$(bc <<< "scale=4; $operand1-$operand2")
            echo ----------------------------------------
            echo Subtraction of $operand1 and $operand2 is $answer
            echo ----------------------------------------
            echo
        elif [[ $choice -eq 3 ]] ; then
            #echo Enter operand1 value:
            #read operand1
            #echo Enter operand2 value:
            #read operand2
	    answer=$(bc <<< "scale=4; $operand1*$operand2")
            echo ----------------------------------------
            echo Multiplication of $operand1 and $operand2 is $answer
            echo ----------------------------------------
            echo
        elif [[ $choice -eq 4 ]] ; then
            #echo Enter operand1 value:
            #read operand1
            #echo Enter operand2 value:
            #read operand2
	    answer=$(bc <<< "scale=4; $operand1/$operand2")
            echo ----------------------------------------
            echo Division of $operand1 and $operand2 is $answer
            echo ----------------------------------------
            echo
        else
            echo ----------------------------------------
            echo Invalid choice.. Please try again
            echo ----------------------------------------
            echo
        fi
    done
else
    echo ----------------------------------------
    echo You either passed too many parameters or too less
    echo than the optimum requirement.
    echo
    echo This program accepts a maximum of 2 arguments or no
    echo argument at all in order to run successfully.
    echo ----------------------------------------
fi
