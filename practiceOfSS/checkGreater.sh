echo "Enter 3 numbers;"
read a b c
if [ $a -gt $b -a $a -gt $c ]
then 
	max=$a
elif [ $b -gt $c ] 
then 
	max=$b
else
	max=$c
fi
echo "Greatest of 3 is : $max"
exit
