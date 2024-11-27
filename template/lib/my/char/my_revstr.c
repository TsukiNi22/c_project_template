/*
** EPITECH PROJECT, 2024
** my_evil_str.c
** File description:
** Return the string but reversed
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>
#include <limits.h>

char *my_revstr(char *str)
{
    char *evil_str;
    int len;

    ERR_DN(PTR_ERR, "In: my_revstr", (!str));
    len = my_strlen(str);
    ERR_DN(UNDEF_ERR, "In: my_revstr 1", (len < 0));
    ERR_DN(UNDEF_ERR, "In: my_revstr 2",
    (my_malloc_c(&evil_str, len) == KO));
    for (int i = 0; str[i]; i++)
        evil_str[len - (i + 1)] = str[i];
    for (int i = 0; str[i]; i++)
        str[i] = evil_str[i];
    free(evil_str);
    return str;
}
