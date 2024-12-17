##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Sample makefile de la ta
##

CC = gcc

TARGET = a.out

W = -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow -Werror

DEBUG = -g -ggdb3

CPPFLAGS = -I ./include/
LDFLAGS = -L ./lib/ -lmy
CFLAGS = $(W)

GLOBAL =	main.c \
		sample.c \
		free_data.c

INIT =		init/init_data.c \
		init/init_flag.c \
		init/init_struct_main.c

FILE = $(GLOBAL) $(INIT)
SRC = $(addprefix src/, $(FILE))
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@make -C lib/my --no-print-directory
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(TARGET)
	@make fclean -C lib/my --no-print-directory

re: fclean $(TARGET)

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
