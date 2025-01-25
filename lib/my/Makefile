##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile de la TA
##

CC := gcc

TARGET := libmy.a
BUILD_DIR := .obj

W := -W -Wall -Wextra -Wpedantic -Wunused-parameter -Wshadow -Werror

DEBUG := -g -ggdb3

CPPFLAGS := -I ../../include/
CFLAGS := $(W)

ifeq ($(d), t)
	CFLAGS := $(DEBUG)
endif

MATH := 	math/my_degree_rad.c \
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

MATRICE :=	matrice/init_matrice.c \
			matrice/transpose_matrice.c \
			matrice/multiplie_matrice.c \
			matrice/str_to_matrice.c \
			matrice/free_matrice.c \
			matrice/reduce_matrice.c \
			matrice/determinant_matrice.c \
			matrice/inverse_matrice.c \
			matrice/cofacteur_matrice.c

MEMORY :=	memory/my_calloc.c \
			memory/my_realloc.c \
			memory/my_malloc.c \
			memory/my_swap.c \
         	memory/my_strdup.c \
			memory/my_memeset.c

WRITE := 	write/my_putnbr_base.c \
			write/my_putchar.c \
			write/my_show_word_array.c \
        	write/my_putnbr.c \
			write/my_putstr.c \
			write/display_matrice.c \
			write/display_linked.c

STRING := 	string/my_strcat.c \
			string/my_strcmp.c \
			string/my_strcpy.c \
			string/my_strlen_stop_at.c \
       		string/my_strlowcase.c \
			string/my_strncat.c \
			string/my_strncmp.c \
			string/my_strncpy.c \
       		string/my_cut_str.c \
			string/my_strlen.c \
			string/my_strstr.c \
			string/my_char_islower.c \
       		string/my_char_isupper.c \
			string/my_str_isalpha.c \
			string/my_str_islower.c \
       		string/my_str_isnum.c \
			string/my_str_isprintable.c \
			string/my_str_isupper.c \
       		string/my_strupcase.c \
			string/my_atof.c \
			string/my_atoi.c \
			string/my_concat_params.c \
       		string/my_itoa.c \
			string/my_strcapitalize.c \
			string/my_ftoa.c \
			string/my_revstr.c \
			string/my_strfind.c \
			string/my_stris.c \
       		string/my_count_occurence.c \
			string/get_fullpath.c \
			string/my_str_to_str_array.c \
			string/my_get_index.c

LINKED := 	linked/linked_add.c \
			linked/linked_add_id.c \
			linked/linked_pop.c \
         	linked/linked_pop_id.c \
			linked/linked_get_data.c

FILE := 	file/get_file.c

ERROR :=	error/error_dispatch.c \
			error/error_print.c \
			error/error_prog.c \
			error/error_custom.c \
			error/error_system.c

OTHERS :=	flag.c

SRC := $(MATH) $(MATRICE) $(MEMORY) $(WRITE) $(STRING) $(LINKED) $(FILE)
SRC += $(ERROR) $(OTHERS)
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rc $@ $^
	@mv $@ ../

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f ../$(TARGET)

.NOTPARALLEL:
re: fclean $(TARGET)

get_unregistered_files:
	@find . -name "*.c" | sed "s/\.\///g" | while read file; do \
        	echo "$(SRC)" | grep -q "$$file" || \
		echo "$$file" >> new_files_detected.txt; \
        done
	@if [ -f new_files_detected.txt ]; then \
                cat new_files_detected.txt;\
                rm -f new_files_detected.txt; \
        fi

get_unknow_files:
	@for file in $(SRC); do \
            if [ ! -f "$$file" ]; then \
                echo "$$file" >> missing_files.txt; \
            fi; \
        done
	@if [ -f missing_files.txt ]; then \
                cat missing_files.txt | sed "s/src\///g"; \
                rm -f missing_files.txt; \
        fi

.PHONY: all clean fclean re get_unregistered_files get_unknow_files
