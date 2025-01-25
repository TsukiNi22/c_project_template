/*
** EPITECH PROJECT, 2025
** print_info.c
** File description:
** Init data with the given flag
*/

#include "string.h"
#include "file.h"
#include "sample.h"
#include "macro.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static int (*flag_function[])(int *, char const **, main_data_t *) = {
    &flag_init_null, // ./binary
    &flag_init_null, // -h
    &flag_init_null, // --help
    &flag_init_null, // -fh
    &flag_init_null, // --full-h
    &flag_init_null  // -H
};

static int my_str_isflag(char **flags, char const *flag, int *indice)
{
    if (!flags || !flag || !indice)
        return err_prog(PTR_ERR, "In: my_str_isflag", KO);
    for (int i = 0; flags[i]; i += 2) {
        if (my_strcmp(flags[i], flag) == 0) {
            *indice = i;
            return true;
        }
    }
    return false;
}

static int clean_flag(char **flags, char *flag)
{
    if (!flags || !flag)
        return err_prog(PTR_ERR, "In: clean_flag", KO);
    for (int i = 0; flags[i]; i++)
        free(flags[i]);
    free(flags);
    free(flag);
    return OK;
}

int init_flag(int argc, char const *argv[], main_data_t *data)
{
    char **flags = NULL;
    char *flag = NULL;
    int res = 2;
    int indice = 0;

    if (!argv)
        return err_prog(PTR_ERR, "In: init_flag", KO);
    flag = get_file("data/flag/flag-list");
    flags = my_str_to_str_array(flag, ":\n", false);
    if (!flags)
        return err_prog(UNDEF_ERR, "In: init_flag 1", KO);
    for (int i = 0; i < argc; i++) {
        res = my_str_isflag(flags, argv[i], &indice);
        if (res == KO)
            return err_prog(UNDEF_ERR, "In: init_flag 2", KO);
        if (res && flag_function[indice / 2](&i, argv, data) == KO)
            return err_prog(UNDEF_ERR, "In: init_flag 3", KO);
    }
    return clean_flag(flags, flag);
}

int flag_init_null(UNUSED int *i, char const *argv[], main_data_t *data)
{
    if (!argv || !data)
        return err_prog(PTR_ERR, "In: flag_init_null", KO);
    return OK;
}
