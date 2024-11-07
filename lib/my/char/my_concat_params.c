/*
** EPITECH PROJECT, 2024
** concat_params.c
** File description:
** All param in one str
*/

#include "char.h"
#include "include.h"
#include "define.h"
#include "error.h"

static int get_size(int ac, char **av)
{
    int size = 0;
    int res;

    if (!av)
        return -1;
    for (int i = 0; i < ac; i++) {
        res = my_strlen(av[i]);
        if (res < 0)
            return err_dispatch(PTR_ERR, "In: concat_params 1.1", -1);
        size += res;
    }
    return size;
}

static int my_strcat_local(char *dest, char const *str, int start)
{
    int len = my_strlen(str);

    if (!dest || !str || len < 0)
        return -1;
    for (int i = 0; i < len; i++)
        dest[start + i] = str[i];
    return 0;
}

static int my_calloc_local(char *str, int size)
{
    if (!str)
        return -1;
    for (int i = 0; i < size; i++)
        str[i] = '\n';
    return 0;
}

char *concat_params(int ac, char **av)
{
    int total_str_size = get_size(ac, av);
    char *str = malloc(sizeof(char) * (total_str_size + ac));
    int actual_place = 0;
    int res;

    if (!av)
        err_dispatch_n(PTR_ERR, "In: concat_params 2");
    if (!str)
        err_dispatch_n(MALLOC_ERR, "In: concat_params");
    if (total_str_size < 0)
        err_dispatch_n(ARGV_ERR, "In: concat_params");
    if (my_calloc_local(str, total_str_size + ac) < 0)
        err_dispatch_n(PTR_ERR, "In: concat_params 3");
    for (int i = 0; i < ac; i++) {
        res = my_strlen(av[i]);
        if (my_strcat_local(str, av[i], actual_place) < 0 || res < 0)
            err_dispatch_n(PTR_ERR, "In: concat_para 4");
        actual_place += res + 1;
    }
    return str;
}
