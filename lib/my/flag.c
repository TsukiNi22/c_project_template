/*
** EPITECH PROJECT, 2024
** print_info.c
** File description:
** Print the info (-h / -fh / -H)
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
    if (!file)
        return err_prog(PTR_ERR, "In: print_file", KO);
    if (my_putstr(1, file) == KO)
        return err_prog(UNDEF_ERR, "In: print_info 2", KO);
    free(file);
    if (path)
        free(path);
    return OK;
}

static int check_flag_help(char const *argv, bool *out)
{
    char *file = NULL;

    if (!argv || !out)
        return err_prog(PTR_ERR, "In: check_flag_help", KO);
    if (my_strcmp(argv, "-h") == 0
        || my_strcmp(argv, "--help") == 0) {
        file = get_file("data/short-description");
        if (print_file(file, NULL) == KO)
            return err_prog(UNDEF_ERR, "In: check_flag_help 1", KO);
        *out = true;
    }
    if (my_strcmp(argv, "-fh") == 0
        || my_strcmp(argv, "--full-help") == 0) {
        file = get_file("data/full-description");
        if (print_file(file, NULL) == KO)
            return err_prog(UNDEF_ERR, "In: check_flag_help 2", KO);
        *out = true;
    }
    return OK;
}

int print_info(int argc, char const *argv[], bool *out)
{
    if (!argv || !out)
        return err_prog(PTR_ERR, "In: print_info", KO);
    if (*out)
        return OK;
    for (int i = 0; i < argc && !(*out); i++) {
        if (check_flag_help(argv[i], out) == KO)
            return err_prog(UNDEF_ERR, "In: print_info", KO);
    }
    return OK;
}

static bool my_str_isin(char **flags, char const *flag, int *indice)
{
    if (!flags || !flag || !indice)
        return err_prog(PTR_ERR, "In: my_str_isin", false);
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

    if (!argv || !out)
        return err_prog(PTR_ERR, "In: check_flag_help", KO);
    if (my_str_isin(flags, argv, &indice)) {
        path = get_full_path("data/flag/", flags[indice + 1]);
        file = get_file(path);
        if (print_file(file, path) == KO || !file)
            return err_prog(UNDEF_ERR, "In: check_flag_help", KO);
        *out = true;
    }
    return OK;
}

int print_info_flag(int argc, char const *argv[], bool *out)
{
    char **flags = NULL;
    char *flag = NULL;

    if (!argv || !out)
        return err_prog(PTR_ERR, "In: print_info_flag", KO);
    flag = get_file("data/flag/flag-list");
    flags = my_str_to_str_array(flag, ":\n", false);
    if (!flags)
        return err_prog(UNDEF_ERR, "In: print_info_flag 1", KO);
    for (int i = 0; i < argc - 1 && !(*out); i++) {
        if (my_strcmp(argv[i + 1], "-H") == 0 &&
            check_flag_up_h(flags, argv[i], out) == KO)
            return err_prog(UNDEF_ERR, "In: print_info_flag 2", KO);
    }
    for (int i = 0; flags[i]; i++)
        free(flags[i]);
    free(flags);
    free(flag);
    return OK;
}
