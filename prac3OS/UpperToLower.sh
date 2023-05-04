#!/usr/bin/env bash
#program to convert Uppercase commandline enteres character to lowercase
read -p "Enter file input file name: " inputFile

echo "original string:"
cat $inputFile

echo "Uppercased string : "
tr '[a-z]' '[A-Z]' < $inputFile