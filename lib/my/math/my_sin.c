/*
** EPITECH PROJECT, 2024
** my_sin.c
** File description:
** The sin function
*/

#include "math.h"
#include "macro.h"
#include "error.h"

float my_sin(float x)
{
    float sum = 1;
    float f1;

    ABS(x);
    if (x < 0)
        return err_dispatch(OVERFLOW, "In: sin", KO);
    for (; x > PI; x -= PI);
    sum = x;
    for (int i = 1; my_factorial(i * 2 + 1) != 84; i++)
        sum += (my_pow(x, i * 2 + 1) / my_factorial(i * 2 + 1)) *
        (1 - 2 * (i % 2));
    return sum;
}
