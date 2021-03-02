#!/bin/bash
gcc -o spacePruebaEXE -ansi -pedantic space.o space_test.o
gcc -Wall -c -ansi -pedantic  space.c
gcc -Wall -c -ansi -pedantic  space_test.c

