for i in $*
do
	if who | grep -s $i > /dev/null
	then 
		echo $i is logged in
	else
		echo $i is not logged in
	fi
done

