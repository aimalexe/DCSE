echo "what kind of trees bear acorns"
read resp

case $resp in 
	[Oo][Aa][Kk]) echo $resp is correct.;;
	*) echo Sorry $resp is incorrect;;
esac

