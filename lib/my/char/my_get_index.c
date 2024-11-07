/*
** EPITECH PROJECT, 2024
** my_get_index.c
** File description:
** Get the index of the char in the given string
*/

#include "error.h"

int my_get_index(char const *str, char const c)
{
    int i = 0;

    if (!str)
        return err_dispatch(PTR_ERR, "In: get_index", -1);
    for (; i[str];) {
        if (i[str] == c)
            return i;
        i++;
    }
    return -1;
}
