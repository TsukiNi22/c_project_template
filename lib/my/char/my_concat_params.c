/*
** EPITECH PROJECT, 2024
** concat_params.c
** File description:
** All param in one str
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"

static int get_size(int ac, char **av)
{
    int size = 0;
    int res;

    ERR_D(PTR_ERR, "In: my_concat_params", KO, (!av));
    for (int i = 0; i < ac; i++) {
        res = my_strlen(av[i]);
        ERR_D(UNDEF_ERR, "In: my_concat_params > get_size", KO, (res < 0));
        size += res;
    }
    return size;
}

char *concat_params(int ac, char **av)
{
    int total_str_size = get_size(ac, av);
    char *str = NULL;
    int res;

    ERR_DN(PTR_ERR, "In: my_concat_params", (!av));
    ERR_DN(ARGV_ERR, "In: my_concat_params", (total_str_size < 0));
    ERR_DN(UNDEF_ERR, "In: my_concat_params",
    (my_malloc_c(&str, total_str_size + ac) == KO));
    for (int i = 0; i < ac; i++)
        ERR_DN(UNDEF_ERR, "In: concat_params 2", (!my_strcat(str, av[i])));
    return str;
}
