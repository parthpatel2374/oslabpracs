#!/usr/bin/env bash
read -p "Enter the decimal number: " decimal
echo -e "\n"

#Calculation for Decimal to Binary
declare -a temp1=()
declare -a Bin=()
num=$decimal
while [ $num -ne 0 ]; do
    val=$((num%2))
    temp1=("${temp1[@]}"  "$val")
    num=$((num/2))
done
j=${#temp1[@]};
while [ $j -ne 0 ]; do
    j=$((j-1))
    val=${temp1[j]} 
    Bin=("${Bin[@]}"  "$val")
done
echo "Binary of $decimal is: " ${Bin[@]}

#Calculation for Decimal to Octal
declare -a temp2=()
declare -a Oct=()
num=$decimal
while [ $num -ne 0 ]; do
    val=$((num%8))
    temp2=("${temp2[@]}"  "$val")
    num=$((num/8))
done
j=${#temp2[@]};
while [ $j -ne 0 ]; do
    j=$((j-1))
    val=${temp2[j]} 
    Oct=("${Oct[@]}"  "$val")
done
echo "Octal of $decimal is: " ${Oct[@]}

#Calculation for Decimal to HexaDecimal
declare -a temp3=()
declare -a Hex=()
num=$decimal
while [ $num -ne 0 ]; do
    val=$((num%16))
    if [ $val -gt 9 ]; then
        case $val in 
            10) val='A' ;;
            11) val='B' ;;
            12) val='C' ;;
            13) val='D' ;;
            14) val='E' ;;
            15) val='F' ;;
        esac
    fi
    temp3=("${temp3[@]}"  "$val")
    num=$((num/16))
done
j=${#temp3[@]};
while [ $j -ne 0 ]; do
    j=$((j-1))
    val=${temp3[j]} 
    Hex=("${Hex[@]}"  "$val")
done
echo "Binary of $decimal is: " ${Hex[@]}