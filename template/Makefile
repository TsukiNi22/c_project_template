##
## EPITECH PROJECT, 2024
## makefile
## File description:
## Sample makfile pour la ta
##

TARGET = a.out
TGR_MY_LIB = libmy.a

LIB_SRCS = $(shell find lib/my -name "*.c")
CFILE = $(shell find src/ -name "*.c")
all: $(TARGET)

$(TARGET):
	@gcc -c $(LIB_SRCS) -I./include/
	@ar rc $(TGR_MY_LIB) *.o
	@gcc $(CFILE) -I ./include/ -L. -lmy -o $(TARGET)

clean:
	@rm -f $(shell find . -name "*.o")

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(TGR_MY_LIB)

re: fclean $(TARGET)
