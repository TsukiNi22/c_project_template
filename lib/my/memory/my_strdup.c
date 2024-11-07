/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** Allocate memory and copy an array in
*/

#include "char.h"
#include "include.h"
#include "define.h"
#include "error.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *array = malloc(len * sizeof(char));

    if (!src)
        err_dispatch_n(PTR_ERR, "In: strdup 1");
    if (!array)
        err_dispatch_n(MALLOC_ERR, "In: strdup");
    if (my_strcpy(array, src) == NULL)
        err_dispatch_n(PTR_ERR, "In: strdup 2");
    array[len] = '\0';
    return array;
}
