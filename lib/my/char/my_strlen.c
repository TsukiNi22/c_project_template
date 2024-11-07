/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** Get the len of a string
*/

#include "error.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return err_dispatch(PTR_ERR, "In: strlen", -1);
    for (; str[len]; len++);
    return len;
}
