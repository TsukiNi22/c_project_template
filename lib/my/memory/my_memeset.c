/*
** EPITECH PROJECT, 2024
** my_memset.c
** File description:
** Set the memory of the ptr to given value
*/

#include "define.h"
#include "error.h"

int my_memset(void *ptr, int value, int size, int type_size)
{
    unsigned char *cast_ptr = NULL;
    unsigned char cast_value = 0;

    if (!ptr)
        return err_prog(PTR_ERR, "In: my_memeset", KO);
    if (size < 1)
        return err_prog(ARGV_ERR, "In: my_memeset", KO);
    cast_ptr = (unsigned char *) ptr;
    cast_value = (unsigned char) value;
    for (int i = 0; i < size * type_size; i++)
        cast_ptr[i] = cast_value;
    return OK;
}