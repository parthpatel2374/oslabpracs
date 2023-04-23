echo "How many numbers do you want?"
read count
a=0; b=1; i=3
echo $a
echo $b
while [ $i -le $count ]
do 
	c=$((a+b))
	echo $c
	a=$b
	b=$c
	i=$((i+1))
done
exit
