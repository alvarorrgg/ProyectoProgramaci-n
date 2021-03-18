#!/bin/bash
gcc -Wall -c -ansi -pedantic -g space.c
gcc -Wall -c -ansi -pedantic -g  space_test.c
gcc -Wall -c -ansi -pedantic -g set.c
gcc -o spacePruebaEXE -ansi -pedantic space.o space_test.o set.o


