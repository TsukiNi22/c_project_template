##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Sample makfile pour la ta
##

TARGET = "a.out"

CFILE=$(shell find . -name "*.c")
OFILE=$(CFILE:.c=.o)

all: $(TARGET)

$(TARGET):
	@gcc $(CFILE) -I include/ -o $(TARGET)

clean:
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(TARGET)
	@rm -f *.gc*

re: fclean $(TARGET)
