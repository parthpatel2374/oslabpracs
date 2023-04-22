#program to convert Uppercase commandline enteres character to lowercase
string=("$@")

echo "original string : "$string
tr '[:lower:]' '[:upper:]' < "$string"

echo "Uppercased string : "$string
exit