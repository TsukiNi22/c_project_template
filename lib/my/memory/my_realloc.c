/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Add place at the end of the given array
*/

#include "char.h"
#include "memory.h"
#include "include.h"
#include "error.h"

char *my_realloc_str(char *str, int add)
{
    char *tmp;
    int size = my_strlen(str);

    if (!str)
        err_dispatch_n(PTR_ERR, "In: realloc_str");
    tmp = malloc(sizeof(char) * (size + add));
    my_calloc_str(tmp, size + add);
    if (!tmp)
        err_dispatch_n(MALLOC_ERR, "In: realloc_str");
    if (my_calloc_str(tmp, size + add) == KO)
        return err_dispatch_n(PTR_ERR, "In: realloc_str");
    tmp = my_strcat(tmp, str);
    free(str);
    return tmp;
}
