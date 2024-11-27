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

    ERR_D(OVERFLOW, "In: my_factorial", KO, (x > 170));
    for (; x > 1; x--)
        sum *= x;
    return sum;
}
