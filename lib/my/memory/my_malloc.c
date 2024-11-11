/*
** EPITECH PROJECT, 2024
** my_malloc.c
** File description:
** For malloc
*/

#include "memory.h"
#include "include.h"
#include "error.h"

void *my_malloc(int size, int type_size)
{
    void *array;

    ERR_DN(ARGV_ERR, "In: my_malloc 1", (size < 1));
    ERR_DN(ARGV_ERR, "In: my_malloc 2", (type_size < 1));
    array = malloc(type_size * size);
    ERR_DN(MALLOC_ERR, "In: my_malloc", (!array));
    ERR_DN(UNDEF_ERR, "In: my_malloc",
    (my_calloc(array, size, type_size) == ERROR));
    return array;
}
