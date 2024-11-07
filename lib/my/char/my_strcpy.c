/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copy a string into another
*/

#include "define.h"
#include "error.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        err_dispatch_n(PTR_ERR, "In: strcpy");
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
