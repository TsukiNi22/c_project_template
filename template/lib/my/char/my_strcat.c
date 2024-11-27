/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concatenates two string
*/

#include "char.h"
#include "define.h"
#include "error.h"

char *my_strcat(char *dest, char const *src)
{
    int len;

    ERR_DN(PTR_ERR, "In: my_strcat", (!dest || !src));
    len = my_strlen(dest);
    ERR_DN(UNDEF_ERR, "In: my_strcat", (len < 0));
    for (int i = 0; src[i]; i++)
        dest[len + i] = src[i];
    return dest;
}
