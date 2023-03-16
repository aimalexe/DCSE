echo 'The parameters passed are: ' $1, $2, $3, $4, $5, $6.
echo 'The name of script is: ' $0.
echo 'The number of parameters passed are' $#.
echo 'The process id is: ' $$.

sum=`expr $1 + $2 + $3 + $4 + $5`
echo "The sum of passed parameters are: " $sum.

prod=`expr $1 \* $2 \* $3 \* $4 \* $5`
echo "The product of passed paremeters are: " $prod.
