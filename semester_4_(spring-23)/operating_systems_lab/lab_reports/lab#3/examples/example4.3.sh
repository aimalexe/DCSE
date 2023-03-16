num1=75
num2=68

if [ $num1 == $num2 ]
then
	echo "These are not strings"

elif [ $num1 -eq $num2 ]
then 
	echo $num1 is equal to $num2

elif [ $num1 -gt $num2 ]
then
        echo $num1 is greater than $num2

elif [ $num1 -lt $num2 ]
then
	echo $num1 is less than $num2
else 
	echo "None condition met."

fi
