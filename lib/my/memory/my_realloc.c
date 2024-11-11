/*
** EPITECH PROJECT, 2024
** my_calloc_str.c
** File description:
** Add place at the end of the given array
*/

#include "memory.h"
#include "include.h"
#include "error.h"

void *my_realloc(void *ptr, int add, int size, int type_size)
{
    void *new;

    ERR_DN(PTR_ERR, "In: my_realloc", (!ptr));
    ERR_DN(ARGV_ERR, "In: my_realloc", (add < 1 || size < 1 || type_size < 1));
    new = my_malloc(size, type_size);
    ERR_DN(UNDEF_ERR, "In: my_realloc", (!new));
    for (int i = 0; i < size * type_size; i++)
        ((unsigned char *) new)[i] = ((unsigned char *) ptr)[i];
    free(ptr);
    return new;
}
