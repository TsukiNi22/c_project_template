/*
** EPITECH PROJECT, 2024
** my_tan.c
** File description:
** The tan function
*/

#include "math.h"
#include "macro.h"
#include "error.h"

double my_tan(float x)
{
    ABS(x);
    if (x < 0)
        return err_dispatch(OVERFLOW, "In: cos", 0);
    return (double) my_sin(x) / (double) my_cos(x);
}
