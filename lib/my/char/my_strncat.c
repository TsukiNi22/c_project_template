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
    int len;

    ERR_DN(PTR_ERR, "In: my_strncat", (!dest || !src));
    len = my_strlen(dest);
    ERR_DN(UNDEF_ERR, "In: my_strncat", (len < 0));
    for (int i = 0; src[i] && i < nb; i++)
        dest[len + i] = src[i];
    return dest;
}
