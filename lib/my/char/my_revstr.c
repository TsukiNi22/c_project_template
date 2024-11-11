/*
** EPITECH PROJECT, 2024
** my_evil_str.c
** File description:
** Return the string but reversed
*/

#include "char.h"
#include "memory.h"
#include "include.h"
#include "define.h"
#include "error.h"

char *my_revstr(char *str)
{
    char *evil_str;
    int len;

    ERR_DN(PTR_ERR, "In: my_revstr", (!str));
    len = my_strlen(str);
    ERR_DN(UNDEF_ERR, "In: my_revstr 1", (len < 0));
    evil_str = my_malloc(len, sizeof(char));
    ERR_DN(UNDEF_ERR, "In: my_revstr 2", (!evil_str));
    for (int i = 0; str[i]; i++)
        evil_str[len - (i + 1)] = str[i];
    for (int i = 0; str[i]; i++)
        str[i] = evil_str[i];
    free(evil_str);
    return str;
}
