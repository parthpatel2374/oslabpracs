echo "Enter name of first file;"
read first
echo "Enter name of second file;"
read second
cat $first > dest.txt
cat $second >> dest.txt
echo "Destination file has contents as ..."
cat dest.txt
exit
