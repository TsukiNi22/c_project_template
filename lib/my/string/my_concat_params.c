/*
** EPITECH PROJECT, 2025
** concat_params.c
** File description:
** All param in one str
*/

#include "string.h"
#include "memory.h"
#include "define.h"
#include "error.h"

static int get_size(int ac, char **av)
{
    int size = 0;
    int res = 0;

    if (!av)
        return err_prog(PTR_ERR, "In: my_concat_params", KO);
    for (int i = 0; i < ac; i++) {
        res = my_strlen(av[i]);
        if (res < 0)
            return err_prog(UNDEF_ERR, "In: my_concat_params > get_size", KO);
        size += res;
    }
    return size;
}

char *concat_params(int ac, char **av)
{
    int total_str_size = get_size(ac, av);
    char *str = NULL;

    if (!av)
        return err_prog_n(PTR_ERR, "In: my_concat_params");
    if (total_str_size < 0)
        return err_prog_n(ARGV_ERR, "In: my_concat_params");
    if (my_malloc_c(&str, total_str_size + ac) == KO)
        return err_prog_n(UNDEF_ERR, "In: my_concat_params");
    for (int i = 0; i < ac; i++) {
        if (!my_strcat(str, av[i]))
            return err_prog_n(UNDEF_ERR, "In: concat_params 2");
    }
    return str;
}
