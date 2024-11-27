/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Add place at the end of the given array
*/

#include "memory.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

int my_realloc_b(bool **ptr, int add, int size)
{
    int type_size = sizeof(bool);
    bool *new;

    ERR_D(PTR_ERR, "In: my_realloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_realloc", KO,
    (add < 1 || size < 1));
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_b(&new, size) == KO));
    for (int i = 0; i < size; i++)
        new[i] = (*ptr)[i];
    free(*ptr);
    (*ptr) = NULL;
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_b(ptr, size) == KO));
    for (int i = 0; i < size; i++)
        (*ptr)[i] = new[i];
    free(new);
    return OK;
}

int my_realloc_c(char **ptr, int add, int size)
{
    char *new;

    ERR_D(PTR_ERR, "In: my_realloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_realloc", KO,
    (add < 1 || size < 1));
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_c(&new, size) == KO));
    for (int i = 0; i < size; i++)
        new[i] = (*ptr)[i];
    free(*ptr);
    (*ptr) = NULL;
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_c(ptr, size) == KO));
    for (int i = 0; i < size; i++)
        (*ptr)[i] = new[i];
    free(new);
    return OK;
}

int my_realloc_i(int **ptr, int add, int size)
{
    int *new;

    ERR_D(PTR_ERR, "In: my_realloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_realloc", KO,
    (add < 1 || size < 1));
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_i(&new, size) == KO));
    for (int i = 0; i < size; i++)
        new[i] = (*ptr)[i];
    free(*ptr);
    (*ptr) = NULL;
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_i(ptr, size) == KO));
    for (int i = 0; i < size; i++)
        (*ptr)[i] = new[i];
    free(new);
    return OK;
}

int my_realloc_f(float **ptr, int add, int size)
{
    float *new;

    ERR_D(PTR_ERR, "In: my_realloc", KO, (!ptr || !(*ptr)));
    ERR_D(ARGV_ERR, "In: my_realloc", KO,
    (add < 1 || size < 1));
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_f(&new, size) == KO));
    for (int i = 0; i < size; i++)
        new[i] = (*ptr)[i];
    free(*ptr);
    (*ptr) = NULL;
    ERR_D(UNDEF_ERR, "In: my_realloc", KO,
    (my_malloc_f(ptr, size) == KO));
    for (int i = 0; i < size; i++)
        (*ptr)[i] = new[i];
    free(new);
    return OK;
}
