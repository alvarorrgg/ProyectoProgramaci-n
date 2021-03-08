#!/bin/bash
        gcc -Wall -c -ansi -pedantic  set.c
        gcc -Wall -c -ansi -pedantic set_test.c
	gcc -o setPruebaEXE -ansi -pedantic set.o set_test.o


