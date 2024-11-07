/*
** EPITECH PROJECT, 2024
** specifier_maj_g.c
** File description:
** Specifier G
*/

#include "char.h"
#include "math.h"
#include "printf.h"
#include "macro.h"
#include "include.h"
#include "error.h"

int specifier_maj_g(printf_data_t *data)
{
    long double nbr = va_arg(data->ap, double);
    long double e = my_log(ABS(nbr), 10);
    int power = e * (1 - 2 * (e < 0)) + (e < 0);
    int precision = get_precision(data->ap, data->precision, 6);

    if (power < precision)
        specifier_maj_g_f(data, precision, nbr);
    else
        specifier_maj_g_e(data, precision, nbr);
    return 0;
}
