/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copy a string into another
*/

#include "define.h"
#include "error.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!dest || !src)
        return err_prog_n(PTR_ERR, "In: my_strncpy");
    for (; i < n && src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
