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

    ERR_D(ARGV_ERR, "In: my_binomial", KO, (n < k || k < 0));
    ERR_D(OVERFLOW, "In: my_binomial", KO, (k > 170 || n > 170));
    if (((long long) n) - n == 0 && ((long long) k) - k == 0)
        result = my_factorial(n) / (my_factorial(k) * my_factorial(n - k));
    else
        result = my_gamma(n) / (my_gamma(k) * my_gamma(n - k));
    return result;
}
