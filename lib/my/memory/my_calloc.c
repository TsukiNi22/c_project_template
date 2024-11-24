/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Set to zero every char of the given array
*/

#include "error.h"
#include <stdbool.h>

int my_calloc_b(bool **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_calloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_calloc", KO, (size < 0));
    for (int i = 0; i < size * sizeof(bool); i++)
        (*ptr)[i] = false;
    return OK;
}

int my_calloc_c(char **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_calloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_calloc", KO, (size < 0));
    for (int i = 0; i < size * sizeof(char); i++)
        (*ptr)[i] = '\0';
    return OK;
}

int my_calloc_i(int **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_calloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_calloc", KO, (size < 0));
    for (int i = 0; i < size * sizeof(int); i++)
        (*ptr)[i] = 0;
    return OK;
}

int my_calloc_f(float **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_calloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_calloc", KO, (size < 0));
    for (int i = 0; i < size * sizeof(float); i++)
        (*ptr)[i] = 0.0;
    return OK;
}
