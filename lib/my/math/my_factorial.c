/*
** EPITECH PROJECT, 2024
** my_factorial.c
** File description:
** A factorial
*/

#include "error.h"

double my_factorial(int x)
{
    double sum = 1;

    if (x > 170)
        return err_dispatch(OVERFLOW, "In: factorial", KO);
    for (; x > 0; x--)
        sum *= x;
    return sum;
}
