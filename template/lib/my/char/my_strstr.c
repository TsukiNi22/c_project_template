/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Find the first occurence of a sting in a string
*/

#include "char.h"
#include "define.h"
#include "error.h"

char *my_strstr(char *str, char const *to_find)
{
    int len;
    int size = 0;
    int i = 0;

    ERR_DN(PTR_ERR, "In: my_strstr", (!str || !to_find));
    len = my_strlen(to_find);
    ERR_DN(UNDEF_ERR, "In: my_strstr", (len < 0));
    for (; size < len && str[i]; i++) {
        if (str[i] == to_find[size])
            size++;
        else
            size = 0;
    }
    if (size >= len)
        return &str[i - len];
    return NULL;
}
