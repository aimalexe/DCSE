echo "what is the capital of Turkiye"
read capital

while test $capital != "Istanbol" 
do
	echo Wrong answer. Please Try again.
	read capital
done
echo This is correct.

