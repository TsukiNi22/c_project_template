##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Sample makefile de la ta
##

CC = gcc

NAME = a.out

W = -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow -Werror

INC = -I ./include/
LIB = -L ./lib/ -lmy

CFLAGS = $(INC) $(LIB) $(W)

GLOBAL =	main.c \
		sample.c \
		clean_data.c

INIT =		init/init_data.c \
		init/init_flag.c \
		init/init_struct_main.c

FILE = $(GLOBAL) $(INIT)
SRC = $(addprefix src/, $(FILE))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/my
	@gcc -o $@ $^ $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C lib/my

re: fclean $(NAME)

get_unregistered_files:
	@find src/ -name "*.c" | while read file; do \
        	echo "$(SRC)" | grep -q "$$file" || \
		echo "$$file" >> new_files_detected.txt; \
        done
	@if [ -f new_files_detected.txt ]; then \
                cat new_files_detected.txt | sed "s/src\///g"; \
                rm -f new_files_detected.txt; \
        fi

get_unknow_files:
	@for file in $(SRC); do \
            if [ ! -f "$$file" ]; then \
                echo "$$file" >> missing_files.txt; \
            fi; \
        done;
	@if [ -f missing_files.txt ]; then \
                cat missing_files.txt | sed "s/src\///g"; \
                rm -f missing_files.txt; \
        fi

.PHONY: all clean fclean re get_unregistered_files get_unknow_files
