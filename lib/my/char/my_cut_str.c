/*
** EPITECH PROJECT, 2024
** my_cut_str.c
** File description:
** Return the array after or befor the given point
*/

#include "char.h"
#include "memory.h"
#include "include.h"
#include "define.h"
#include "error.h"

static int get_alloc_size(char const *str, int before, int cut_place)
{
    int res = my_strlen(str);

    ERR_D(PTR_ERR, "In: my_cut_str > get_alloc_size", KO, (!str));
    ERR_D(UNDEF_ERR, "In: my_cut_str > get_alloc_size", KO, (res < 0));
    if (before)
        return cut_place - 1;
    return res - cut_place;
}

char *my_cut_str(const char *str, const int before, int cut_place)
{
    char *new_str;
    int actual_place = 0;
    int res;

    ERR_DN(PTR_ERR, "In: my_cut_str", (!str));
    res = my_strlen(str);
    ERR_DN(UNDEF_ERR, "In: my_cut_str", (res < 0));
    ERR_DN(ARGV_ERR, "In: my_cut_str", (1 > cut_place || cut_place > res));
    new_str = my_malloc(get_alloc_size(str, before, cut_place), sizeof(char));
    ERR_DN(MALLOC_ERR, "In: my_cut_str", (!new_str));
    for (int i = 0; str[i]; i++) {
        if ((i < cut_place && before) || (i > cut_place && !before)) {
            new_str[actual_place] = str[i];
            actual_place++;
        }
    }
    return new_str;
}
