if [ -d $1 ]

then

	echo "$1 is directory."

	cf=$(find $1 -type f | wc -l)

	echo "Total number of files: $cf"

else

	echo "$1 is not a directory"

fi
