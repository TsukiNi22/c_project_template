/*
** EPITECH PROJECT, 2024
** print_info.c
** File description:
** Init data with the given flag
*/

#include "char.h"
#include "file.h"
#include "sample.h"
#include "macro.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static int (*flag_function[])(int, char const **, main_data_t *) = {
    &flag_init_null,
    &flag_init_null,
    &flag_init_null,
    &flag_init_null,
    &flag_init_null,
    &flag_init_null
};

static int my_str_isflag(char **flags, char const *flag, int *indice)
{
    ERR_D(PTR_ERR, "In: my_str_isflag", KO, (!flags || !flag));
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
    ERR_D(PTR_ERR, "In: clean_flag", KO, (!flags || !flag));
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

    ERR_D(PTR_ERR, "In: init_flag", KO, (!argv));
    flag = get_file("data/flag/flag-list");
    flags = my_str_to_str_array(flag, ":\n", false);
    ERR_D(UNDEF_ERR, "In: init_flag 1", KO, (!flags));
    for (int i = 0; i < argc; i++) {
        res = my_str_isflag(flags, argv[i], &indice);
        ERR_D(UNDEF_ERR, "In: init_flag 2", KO, (res == 2));
        if (res) {
            ERR_D(UNDEF_ERR, "In: init_flag 3", KO,
            (flag_function[indice](i, argv, data) == KO));
        }
    }
    return clean_flag(flags, flag);
}

int flag_init_null(int argc, char const *argv[], main_data_t *data)
{
    ERR_D(PTR_ERR, "In: flag_init_null", KO, (argc || !argv || !data));
    return OK;
}
