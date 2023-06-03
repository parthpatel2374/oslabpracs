echo "Enter value of a :"
read a
echo "Enter value of b :"
read b
echo "values of a&b are $a, $b"
val=`expr $a + $b`
echo "Sum of a&b = $val"
exit
