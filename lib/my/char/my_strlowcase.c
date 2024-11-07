/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Make all char in uppercase
*/

#include "define.h"
#include "error.h"

char *my_strlowcase(char *str)
{
    if (!str)
        err_dispatch_n(PTR_ERR, "In: strlowcase");
    for (int i = 0; str[i]; i++) {
        if ((int) str[i] < 91 && (int) str[i] > 64)
            str[i] = (char) ((int) str[i] + 32);
    }
    return str;
}
