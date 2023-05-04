#!/usr/bin/env bash
read -p "Enter three numbers: " a b c

if [ $a -gt $b ] && [ $a -gt $c ]; then
    echo -e "The greatest is $a\n"
else 
    if [ $b -gt $c ]; then
        echo -e "The greatest is $b\n"
    else
        echo -e "The greatest is $c\n"
    fi
fi
