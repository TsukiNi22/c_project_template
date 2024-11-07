/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swaps the content of two intergers
*/

#include "error.h"

int my_swap(int *a, int *b)
{
    int tempo = *a;

    if (!a || !b)
        return err_dispatch(PTR_ERR, "In: swap", KO);
    *a = *b;
    *b = tempo;
    return 0;
}
