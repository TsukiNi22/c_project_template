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
    ERR_D(PTR_ERR, "In: print_file", KO, (!file));
    ERR_D(UNDEF_ERR, "In: print_info 2", KO,
    (my_putstr(1, file) == KO));
    free(file);
    if (path)
        free(path);
    return OK;
}

static int check_flag_help(char const *argv, bool *out)
{
    char *file = NULL;

    ERR_D(PTR_ERR, "In: check_flag_help", KO, (!argv || !out));
    if (my_strcmp(argv, "-h") == 0
        || my_strcmp(argv, "--help") == 0) {
        file = get_file("data/short-description");
        ERR_D(UNDEF_ERR, "In: check_flag_help 1", KO, (!file));
        ERR_D(UNDEF_ERR, "In: check_flag_help 2", KO,
        (print_file(file, NULL) == KO));
        *out = true;
    }
    if (my_strcmp(argv, "-fh") == 0
        || my_strcmp(argv, "--full-help") == 0) {
        file = get_file("data/full-description");
        ERR_D(UNDEF_ERR, "In: check_flag_help 3", KO, (!file));
        ERR_D(UNDEF_ERR, "In: check_flag_help 4", KO,
        (print_file(file, NULL) == KO));
        *out = true;
    }
    return OK;
}

int print_info(int argc, char const *argv[], bool *out)
{
    ERR_D(PTR_ERR, "In: print_info", KO, (!argv || !out));
    for (int i = 0; i < argc && !(*out); i++)
        ERR_D(UNDEF_ERR, "In: print_info", KO,
        (check_flag_help(argv[i], out) == KO));
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

static int check_flag_up_h(char **flags, char const *argv, bool *out)
{
    char *file = NULL;
    char *path = NULL;
    int indice = 0;

    ERR_D(PTR_ERR, "In: check_flag_help", KO, (!argv || !out));
    if (my_str_isin(flags, argv, &indice)) {
        path = get_full_path("data/flag/", flags[indice + 1]);
        file = get_file(path);
        ERR_D(UNDEF_ERR, "In: check_flag_help", KO,
        (print_file(file, path) == KO || !file));
        *out = true;
    }
    return OK;
}

int print_info_flag(int argc, char const *argv[], bool *out)
{
    char **flags = NULL;
    char *flag = NULL;

    ERR_D(PTR_ERR, "In: print_info_flag", KO, (!argv || !out));
    flag = get_file("data/flag/flag-list");
    flags = my_str_to_str_array(flag, ":\n", false);
    ERR_D(UNDEF_ERR, "In: print_info_flag 1", KO, (!flags));
    for (int i = 0; i < argc - 1 && !(*out); i++) {
        if (my_strcmp(argv[i + 1], "-H") == 0)
            ERR_D(UNDEF_ERR, "In: print_info_flag 2", KO,
            (check_flag_up_h(flags, argv[i], out) == KO));
    }
    for (int i = 0; flags[i]; i++)
        free(flags[i]);
    free(flags);
    free(flag);
    return OK;
}
