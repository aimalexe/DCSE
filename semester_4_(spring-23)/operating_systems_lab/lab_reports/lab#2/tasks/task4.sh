echo "Please Enter source file name: \c"
read sourceFile
touch $sourceFile

echo "Enter target file name: \c"
read targetFile

mkdir copiedTo

cp $sourceFile ./copiedTo/$targetFile
echo $sourceFile is copied to ./copiedTo/$targetFile succefully!

rm $sourceFile ./copiedTo/$targetFile
rmdir copiedTo
