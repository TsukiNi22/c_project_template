#!/bin/bash

CFILE=$(find . -name "*.c")

gcc -c $CFILE -I../../include

TARGET="libmy.a"
OFILE=$(find . -name "*.o")
ar rc $TARGET $OFILE

rm $OFILE
