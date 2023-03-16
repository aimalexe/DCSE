if  [ -f $1 ]
then 
	echo "The given argument is a file"
elif [ -d $1 ]
then
	echo "The given argument is a directory"
else
	echo "No such file exists"
fi
