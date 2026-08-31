#!/usr/bin/env bash


clang-format -n *.cpp
g++ -o lab$1 *.cpp
# clear 
./lab$1
