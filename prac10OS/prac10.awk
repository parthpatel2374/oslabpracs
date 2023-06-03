#!/usr/bin/awk
# Returns Uppercased string
function find_uppercase(str){
   string = toupper(str)
   return string
}
# Main function
function main(stringg){
   
   #Find Uppercase of the string
   result = find_uppercase(stringg)
   print "Input string =", stringg
   print "Uppercased string =", result
}
# Script execution starts here
BEGIN {
   main("hi hello how do you do!")
}