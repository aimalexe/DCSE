sum=0
for i in $*
do
	sum=`expr $sum + $i`
done 
echo "The sum is: " $sum.
