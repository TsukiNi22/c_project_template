##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Make FILLe De AL TATATatatatataaaaaaaaaa
##

TARGET="libmy.a"

CFILE=$(shell find . -name "*.c")
OFILE=$(CFILE:.c=.o)
OFILE=$(shell find . -name "*.o")

default: CompileFileLib CompileArchiveLib MoveFile

CompileFileLib:
	@gcc -c $(CFILE) -I../../include

CompileArchiveLib:
	@ar rc $(TARGET) $(OFILE)

MoveFile:
	@cp $(TARGET) ../

clean:
	@rm -f $(OFILE)
