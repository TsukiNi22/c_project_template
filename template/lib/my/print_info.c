/*
** EPITECH PROJECT, 2024
** print_info.c
** File description:
** Print the executable info (-h)
*/

#include "char.h"
#include "file.h"
#include "write.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>

static int print_file(char *file)
{
    ERR_D(PTR_ERR, "In: print_file", EPITECH_ERR, (!file));
    ERR_D(UNDEF_ERR, "In: printf_info 2", EPITECH_ERR,
    (my_putstr(1, file) == KO));
    free(file);
    return OK;
}

int print_info(int argc, char const *argv[])
{
    char *file = NULL;

    ERR_D(PTR_ERR, "In: printf_info", EPITECH_ERR, (!argv));
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0
            || my_strcmp(argv[i], "--help") == 0) {
            file = get_file("data/short-description");
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR, (!file));
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR,
            (print_file(file) == KO));
        }
        if (my_strcmp(argv[i], "-fh") == 0
            || my_strcmp(argv[i], "--full-help") == 0) {
            file = get_file("data/full-description");
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR, (!file));
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR,
            (print_file(file) == KO));
        }
    }
    return OK;
}

int print_info_flag(int argc, char const *argv[])
{
    char *file_path = NULL;
    char *file = NULL;
    char *flag = NULL;

    ERR_D(PTR_ERR, "In: printf_info_flag", EPITECH_ERR, (!argv));
    flag = get_file("data/falg/flag-list");
    ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR, (!file));
    for (int i = 0; i < argc; i++) {
        if (my_strstr(flag, argv[i]) != NULL) {
            file = get_file(file_path);
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR, (!file));
            ERR_D(UNDEF_ERR, "In: printf_info 1", EPITECH_ERR,
            (print_file(file) == KO));
        }
    }
    free(flag);
    return OK;
}
