/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Set to zero every char of the given array
*/

#include "error.h"

int my_calloc(void *ptr, int size, int type_size)
{
    unsigned char *cast_ptr = (unsigned char *) ptr;

    ERR_D(PTR_ERR, "In: my_calloc", KO, (!ptr));
    ERR_D(ARGV_ERR, "In: my_calloc", KO, (size < 0));
    for (int i = 0; i < size * type_size; i++)
        cast_ptr[i] = 0;
    return OK;
}
