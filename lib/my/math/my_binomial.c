/*
** EPITECH PROJECT, 2024
** my_binomial.c
** File description:
** My binomial
*/

#include "math.h"
#include "error.h"

int my_binomial(float n, float k)
{
    float result;

    if (!(n >= k && k >= 0))
        return err_dispatch(ARGV_ERR, "In: binomial", -1);
    if (k > 170)
        return err_dispatch(OVERFLOW, "In: binomial", -1);
    if (((int) n) - n == 0 && ((int) k) - k == 0)
        result = my_factorial(n) / (my_factorial(k) * my_factorial(n - k));
    else
        result = my_gamma(n) / (my_gamma(k) * my_gamma(n - k));
    return result;
}
