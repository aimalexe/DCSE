echo "Please enter username to login? "
read username

until who | grep $username
do 
	sleep 0.5
done
echo $username is logged in.

