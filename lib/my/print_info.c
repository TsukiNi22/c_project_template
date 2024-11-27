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
#include <stdbool.h>

static int print_file(char *file, char *path)
{
    ERR_D(PTR_ERR, "In: print_file", EPITECH_ERR, (!file));
    ERR_D(UNDEF_ERR, "In: printf_info 2", EPITECH_ERR,
    (my_putstr(1, file) == KO));
    free(file);
    if (path)
        free(path);
    return OK;
}

int print_info(int argc, char const *argv[])
{
    char *file = NULL;

    ERR_D(PTR_ERR, "In: print_info", EPITECH_ERR, (!argv));
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0
            || my_strcmp(argv[i], "--help") == 0) {
            file = get_file("data/short-description");
            ERR_D(UNDEF_ERR, "In: print_info 1", EPITECH_ERR, (!file));
            ERR_D(UNDEF_ERR, "In: print_info 1", EPITECH_ERR,
            (print_file(file, NULL) == KO));
        }
        if (my_strcmp(argv[i], "-fh") == 0
            || my_strcmp(argv[i], "--full-help") == 0) {
            file = get_file("data/full-description");
            ERR_D(UNDEF_ERR, "In: print_info 1", EPITECH_ERR, (!file));
            ERR_D(UNDEF_ERR, "In: print_info 1", EPITECH_ERR,
            (print_file(file, NULL) == KO));
        }
    }
    return OK;
}

static bool my_str_isin(char **flags, char const *flag, int *indice)
{
    ERR_D(PTR_ERR, "In: my_str_isin", false, (!flags || !flag || !indice));
    for (int i = 0; flags[i]; i += 2) {
        if (my_strcmp(flags[i], flag) == 0) {
            *indice = i;
            return true;
        }
    }
    return false;
}

static int clean(char **flags, char *flag)
{
    for (int i = 0; flags[i]; i++)
        free(flags[i]);
    free(flags);
    free(flag);
    return OK;
}

int print_info_flag(int argc, char const *argv[])
{
    char **flags = NULL;
    char *path = NULL;
    char *file = NULL;
    char *flag = NULL;
    int indice = 0;

    ERR_D(PTR_ERR, "In: printf_info_flag", EPITECH_ERR, (!argv));
    flag = get_file("data/flag/flag-list");
    flags = my_str_to_str_array(flag, ":\n", false);
    ERR_D(UNDEF_ERR, "In: print_info_flag 1", EPITECH_ERR, (!flags));
    for (int i = 0; i < argc - 1; i++) {
        if (my_str_isin(flags, argv[i], &indice)
            && my_strcmp(argv[i + 1], "-H") == 0) {
            path = get_full_path("data/flag/", flags[indice + 1]);
            file = get_file(path);
            ERR_D(UNDEF_ERR, "In: print_info_flag 2", EPITECH_ERR,
            (print_file(file, path) == KO || !file));
        }
    }
    return clean(flags, flag);
}
