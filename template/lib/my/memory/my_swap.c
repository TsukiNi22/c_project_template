/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swaps the content of two ptr
*/

#include "error.h"

int my_swap_c(char *a, char *b)
{
    char tmp = (*a);

    ERR_D(PTR_ERR, "In: my_swap", KO, (!a || !b));
    (*a) = (*b);
    (*b) = tmp;
    return OK;
}

int my_swap_i(int *a, int *b)
{
    int tmp = (*a);

    ERR_D(PTR_ERR, "In: my_swap", KO, (!a || !b));
    (*a) = (*b);
    (*b) = tmp;
    return OK;
}

int my_swap_f(float *a, float *b)
{
    float tmp = (*a);

    ERR_D(PTR_ERR, "In: my_swap", KO, (!a || !b));
    (*a) = (*b);
    (*b) = tmp;
    return OK;
}
