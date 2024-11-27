##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile de la TA
##

CC = gcc

NAME = libmy.a

W = -Wall -Wextra -Wpedantic -Wconversion -Wshadow

INC = -I ../../include/

CFLAGS = $(INC) $(W)

MATH = 		math/my_degree_rad.c \
		math/my_gamma.c \
		math/my_log.c \
		math/my_pow.c \
       		math/my_rad_degree.c \
		math/my_sqrt.c \
		math/my_binomial.c \
       		math/my_factorial.c \
		math/my_sin.c \
		math/my_tan.c \
		math/my_cos.c \
       		math/my_isneg.c \
		math/my_find_prime_sup.c \
		math/my_convertnbr_base.c \
       		math/my_is_prime.c \
		math/my_sort_int_array.c \
		math/my_get_rand.c

MEMORY =	memory/my_calloc.c \
		memory/my_realloc.c \
		memory/my_malloc.c \
		memory/my_swap.c \
         	memory/my_strdup.c

WRITE = 	write/my_putnbr_base.c \
		write/my_putchar.c \
		write/my_show_word_array.c \
        	write/my_putnbr.c \
		write/my_putstr.c

CHAR = 		char/my_strcat.c \
		char/my_strcmp.c \
		char/my_strcpy.c \
		char/my_strlen_stop_at.c \
       		char/my_strlowcase.c \
		char/my_strncat.c \
		char/my_strncmp.c \
		char/my_strncpy.c \
       		char/my_cut_str.c \
		char/my_strlen.c \
		char/my_strstr.c \
		char/my_char_islower.c \
       		char/my_char_isupper.c \
		char/my_str_isalpha.c \
		char/my_str_islower.c \
       		char/my_str_isnum.c \
		char/my_str_isprintable.c \
		char/my_str_isupper.c \
       		char/my_strupcase.c \
		char/my_atof.c \
		char/my_atoi.c \
		char/my_concat_params.c \
       		char/my_itoa.c \
		char/my_strcapitalize.c \
		char/my_ftoa.c \
		char/my_revstr.c \
       		char/my_str_to_word_array.c \
		char/my_strfind.c \
		char/my_stris.c \
       		char/my_count_occurence.c \
		char/get_fullpath.c \
		char/my_str_to_str_array.c

LINKED = 	linked/linked_add.c \
		linked/linked_add_id.c \
		linked/linked_pop.c \
         	linked/linked_pop_id.c \
		linked/linked_get_data.c

FILE = 		file/get_file.c


OTHERS = 	print_info.c \
		error_handling.c

SRC = $(MATH) $(MEMORY) $(WRITE) $(CHAR) $(LINKED) $(FILE) $(OTHERS)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@mv $@ ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
