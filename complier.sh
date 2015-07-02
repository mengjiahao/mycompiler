#!/bin/sh
./complier.out < testcomp.cpp 
as --32 -o out.o out.s
ld -melf_i386 --dynamic-linker /lib/ld-linux.so.2 out.o -lc
