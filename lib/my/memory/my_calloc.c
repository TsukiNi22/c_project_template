/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Set to zero every char of the given array
*/

#include "error.h"

int my_calloc_float(float *array, int size)
{
    if (!array)
        return err_dispatch(PTR_ERR, "In: calloc_float", KO);
    if (size < 0)
        return err_dispatch(ARGV_ERR, "In: calloc_float", KO);
    for (int i = 0; i < size; i++)
        array[i] = 0;
    return 0;
}

int my_calloc_int(int *array, int size)
{
    if (!array)
        return err_dispatch(PTR_ERR, "In: calloc_int", KO);
    if (size < 0)
        return err_dispatch(ARGV_ERR, "In: calloc_int", KO);
    for (int i = 0; i < size; i++)
        array[i] = 0;
    return 0;
}

int my_calloc_str(char *str, int size)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: calloc_str", KO);
    if (size < 0)
        return err_dispatch(ARGV_ERR, "In: calloc_str", KO);
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return 0;
}
