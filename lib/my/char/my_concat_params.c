/*
** EPITECH PROJECT, 2024
** concat_params.c
** File description:
** All param in one str
*/

#include "char.h"
#include "include.h"
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
    char *str;
    int res;

    ERR_DN(PTR_ERR, "In: my_concat_params", (!av));
    ERR_DN(ARGV_ERR, "In: my_concat_params", (total_str_size < 0));
    str = my_malloc(total_str_size + ac, sizeof(char));
    ERR_DN(UNDEF_ERR, "In: my_concat_params", (!str));
    for (int i = 0; i < ac; i++)
        ERR_DN(UNDEF_ERR, "In: concat_params 2", (!my_strcat(str, av[i])));
    return str;
}
