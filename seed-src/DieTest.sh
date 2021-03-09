#!/bin/bash
gcc -Wall -c -ansi -pedantic  die.c
gcc -Wall -c -ansi -pedantic  die_test.c
gcc -o diePruebaEXE -ansi -pedantic die.o die_test.o

