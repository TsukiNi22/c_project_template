/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concatenates two string
*/

#include "char.h"
#include "define.h"
#include "error.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);

    if (!dest || !src || len < 0)
        err_dispatch_n(PTR_ERR, "In: strncat");
    for (int i = 0; src[i] && i < nb; i++)
        dest[len + i] = src[i];
    return dest;
}
