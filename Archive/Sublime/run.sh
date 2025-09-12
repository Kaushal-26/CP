#!/usr/bin/bash

set -eu

# For Colored Output
yellow=$(tput setaf 3)
red=$(tput setaf 1)
blue=$(tput setaf 4)
magenta=$(tput setaf 5)
cyan=$(tput setaf 6)
normal=$(tput sgr0)


# Pass a File
if [[ $# -eq 0 ]]
then 
	echo "${red}Pass a File of this Directory: ${normal}"
	exit 1
fi 

# File Must Exist
file=$1
if test -f "$file"
then
	echo "${yellow}File Found${normal}"
else
	echo "${red}File does not exists${normal}"
	exit 1
fi

# Compliation Variants
variants=""
if [[ $# -eq 2 ]]
then 
	variants=$2
	if [[ $variants == -d ]]
	then
		variants="-DKaushal_26"
	else
		echo "${red}Wrong Arguments${normal}"
		exit 1
	fi
fi



# Make Exexutable File
executable=./z

# Compilation stats
Warnings="-Wall -H -Wl,--stack=1073741824"

#Compilation Started
echo "${magenta}Compiling...${normal}"
g++ $Warnings $variants -O2 -std=c++20 $file -o $executable

# Code Running
echo "${cyan}Running...${normal}"
"$executable"