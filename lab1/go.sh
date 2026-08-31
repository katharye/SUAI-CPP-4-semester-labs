#!/usr/bin/env bash


clang-format -n *.cpp
g++ -Wall -Werror -Wextra -o lab$1 *.cpp
# clear 
./lab$1
