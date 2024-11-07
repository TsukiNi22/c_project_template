/*
** EPITECH PROJECT, 2024
** my_evil_str.c
** File description:
** Return the string but reversed
*/

#include "char.h"
#include "define.h"
#include "error.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char evil_str[len];

    if (!str || len < 0)
        err_dispatch_n(PTR_ERR, "In: revstr");
    evil_str[len] = '\0';
    for (int i = 0; str[i]; i++)
        evil_str[len - (i + 1)] = str[i];
    for (int i = 0; str[i]; i++)
        str[i] = evil_str[i];
    return str;
}
