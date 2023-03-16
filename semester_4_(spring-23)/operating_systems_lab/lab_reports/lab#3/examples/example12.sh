echo "Enter Three Numbers to find largest"
echo "Enter first number? "
read n1

echo "Enter second number? "
read n2

echo "Enter Third number?"
read n3

if test $n1 -gt $n2
then
	if test $n1 -gt $n3
	then
		echo $n1 is greatest
	else
		echo $n3 is greatest
	fi

elif test $n2 -gt $n3
then 
	if test $n2 -gt $n1
	then 
		echo $n2 is greatest
	else
		echo $n1 is gretest
	fi

elif test $n3 -gt $n1
then
	if test $n3 -gt $n2
	then
		echo $n3 is greatest
	else
		echo $n1 is greatest
	fi
fi


