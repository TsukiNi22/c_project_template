/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** Allocate memory and copy an array in
*/

#include "char.h"
#include "memory.h"
#include "include.h"
#include "define.h"
#include "error.h"

char *my_strdup(char const *src)
{
    char *str;

    ERR_DN(PTR_ERR, "In: my_strdup 1", (!src));
    str = my_malloc(my_strlen(src) + 1, sizeof(char));
    ERR_DN(MALLOC_ERR, "In: my_strdup", (!str));
    ERR_DN(PTR_ERR, "In: my_strdup 2", (!my_strcpy(str, src)));
    return str;
}
