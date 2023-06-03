read -p "Enter the number to get factorial of : " num
n=$num
fact=1

while [ $n -gt 1 ]
do
	fact=$((fact*n))
	n=$((n-1))
done

echo "The factorial of $num is $fact"
exit
 
