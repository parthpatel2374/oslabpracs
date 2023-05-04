#!/usr/bin/env bash

read -p "Enter user name: " user_name
echo ""

who > logging_info

if grep $user_name logging_info
then 
    echo "$user_name is logged in"
else 
    echo "$user_name is not logged in"
fi
    