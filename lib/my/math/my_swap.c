/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swaps the content of two intergers
*/

#include "error.h"

int my_swap(int *a, int *b)
{
    int tmp = *a;

    ERR_D(PTR_ERR, "In: my_swap", KO, (!a || !b));
    *a = *b;
    *b = tmp;
    return OK;
}
