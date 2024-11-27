##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Sample makefile de la ta
##

CC = gcc

NAME = a.out

W = -Wall -Wextra -Wpedantic -Wconversion -Wshadow

INC = -I ./include/
LIB = -L ./lib/ -lmy

CFLAGS = $(INC) $(LIB) $(W)

GLOBAL =	main.c \
		sample.c \
		clean_data.c

INIT =		init/init_data.c \
		init/init_struct_main.c

FILE = $(GLOBAL) $(INIT)
SRC = $(addprefix src/, $(FILE))
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/my
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C lib/my

re: fclean $(NAME)

.PHONY: all clean fclean re
