/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** Get the len of a string
*/

#include "error.h"

int my_strlen_stop_at(char const *str, char c)
{
    int len = 0;

    ERR_D(PTR_ERR, "In: my_strlen", KO, (!str));
    for (; str[len] && str[len] != c; len++);
    return len;
}
