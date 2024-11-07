/*
** EPITECH PROJECT, 2024
** my_cos.c
** File description:
** The cos function
*/

#include "math.h"
#include "macro.h"
#include "error.h"

float my_cos(float x)
{
    float sum = 1;

    ABS(x);
    if (x < 0)
        return err_dispatch(OVERFLOW, "In: cos", KO);
    for (; x > PI; x -= PI);
    for (int i = 1; my_factorial(i * 2) != 84; i++)
        sum += (my_pow(x, i * 2) / my_factorial(i * 2)) * (1 - 2 * (i % 2));
    return sum;
}
