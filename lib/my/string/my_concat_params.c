/*
** EPITECH PROJECT, 2025
** concat_params.c
** File description:
** All param in one str
*/

#include "my_string.h"
#include "memory.h"
#include "define.h"
#include "error.h"

static int get_size(int argc, char **argv)
{
    int size = 0;
    int res = 0;

    if (!argv)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    for (int i = 0; i < argc; i++) {
        res = my_strlen(argv[i]);
        if (res < 0)
            return err_prog(UNDEF_ERR, KO, ERR_INFO);
        size += res;
    }
    return size;
}

char *concat_params(int argc, char **argv)
{
    int total_str_size = 0;
    char *str = NULL;

    if (!argv)
        return err_prog_n(PTR_ERR, ERR_INFO);
    total_str_size = get_size(argc, argv);
    if (total_str_size < 0)
        return err_prog_n(ARGV_ERR, ERR_INFO);
    if (my_malloc_c(&str, total_str_size + argc) == KO)
        return err_prog_n(UNDEF_ERR, ERR_INFO);
    for (int i = 0; i < argc; i++) {
        if (!my_strcat(str, argv[i]))
            return err_prog_n(UNDEF_ERR, ERR_INFO);
    }
    return str;
}
