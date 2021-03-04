#!/bin/bash
gcc -Wall -c -ansi -pedantic  space.c
gcc -Wall -c -ansi -pedantic  space_test.c
gcc -Wall -c -ansi -pedantic set.c
gcc -o spacePruebaEXE -ansi -pedantic space.o space_test.o set.o


