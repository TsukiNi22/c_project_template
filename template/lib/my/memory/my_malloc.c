/*
** EPITECH PROJECT, 2024
** my_malloc.c
** File description:
** For malloc
*/

#include "memory.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

int my_malloc_b(bool **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_malloc", KO, (!ptr));
    ERR_D(ARGV_ERR, "In: my_malloc", KO, (size < 1));
    (*ptr) = malloc(sizeof(bool) * size);
    ERR_D(MALLOC_ERR, "In: my_malloc", KO, (!(*ptr)));
    ERR_D(UNDEF_ERR, "In: my_malloc", KO,
    (my_calloc_b(ptr, size) == ERROR));
    return OK;
}

int my_malloc_c(char **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_malloc", KO, (!ptr));
    ERR_D(ARGV_ERR, "In: my_malloc", KO, (size < 1));
    (*ptr) = malloc(sizeof(char) * size);
    ERR_D(MALLOC_ERR, "In: my_malloc", KO, (!(*ptr)));
    ERR_D(UNDEF_ERR, "In: my_malloc", KO,
    (my_calloc_c(ptr, size) == ERROR));
    return OK;
}

int my_malloc_i(int **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_malloc", KO, (!ptr));
    ERR_D(ARGV_ERR, "In: my_malloc", KO, (size < 1));
    (*ptr) = malloc(sizeof(int) * size);
    ERR_D(MALLOC_ERR, "In: my_malloc", KO, (!(*ptr)));
    ERR_D(UNDEF_ERR, "In: my_malloc", KO,
    (my_calloc_i(ptr, size) == ERROR));
    return OK;
}

int my_malloc_f(float **ptr, int size)
{
    ERR_D(PTR_ERR, "In: my_malloc", KO, (!ptr));
    ERR_D(ARGV_ERR, "In: my_malloc", KO, (size < 1));
    (*ptr) = malloc(sizeof(float) * size);
    ERR_D(MALLOC_ERR, "In: my_malloc", KO, (!(*ptr)));
    ERR_D(UNDEF_ERR, "In: my_malloc", KO,
    (my_calloc_f(ptr, size) == ERROR));
    return OK;
}
