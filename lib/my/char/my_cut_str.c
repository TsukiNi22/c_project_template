/*
** EPITECH PROJECT, 2024
** my_cut_str.c
** File description:
** Return the array after or befor the given point
*/

#include "char.h"
#include "include.h"
#include "define.h"
#include "error.h"

static int get_alloc_size(char const *str, int before, int cut_place)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: cut_str 2.1", 0);
    if (before)
        return cut_place - 1;
    else
        return my_strlen(str) - cut_place;
}

char *my_cut_str(const char *str, const int before, int cut_place)
{
    int actual_place = 0;
    char *new_str;
    int res = my_strlen(str);

    if (!str || res < 0)
        err_dispatch_n(PTR_ERR, "In: cut_str 1");
    if (1 > cut_place || cut_place > res)
        err_dispatch_n(ARGV_ERR, "In: cut_str");
    new_str = malloc(sizeof(char) * get_alloc_size(str, before, cut_place));
    if (!new_str)
        err_dispatch_n(MALLOC_ERR, "In: cut_str");
    for (int i = 0; str[i]; i++) {
        if ((i < cut_place && before) || (i > cut_place && !before)) {
            new_str[actual_place] = str[i];
            actual_place++;
        }
    }
    return new_str;
}
