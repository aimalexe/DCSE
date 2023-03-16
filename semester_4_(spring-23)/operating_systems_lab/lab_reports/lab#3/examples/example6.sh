echo "1. User information"
echo

echo "2. Directory Listing"
echo

echo "3. Date and Time"
echo

echo "4. Current Directory"
echo

echo "Enter your choice? (1, 2, 3, 4): \e"
read choice

case $choice in
	1) who;;
	2) ls -l;;
	3) date;;
	4) pwd;;
	*) echo Wrong choice selected.
esac

