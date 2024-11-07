/*
** EPITECH PROJECT, 2024
** specifier_maj_f.c
** File description:
** Specifier F
*/

#include "char.h"
#include "math.h"
#include "write.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int my_round(char *my_double, int i)
{
    int ret;

    if (my_double[i] == '.')
        i++;
    ret = (my_double[i] >= '5');
    while (ret && i > 0 && my_double[i]) {
        if (my_double[i - 1] == '.')
            i--;
        my_double[i - 1] += ret;
        if (my_double[i - 1] > '9') {
            ret = 1;
            my_double[i - 1] = '0';
        } else
            ret = 0;
        i--;
    }
    return 0;
}

static int handle_zero_precision(char *my_double, int precision,
    int flag_hashtag)
{
    int i = 0;

    if (precision != 0)
        return 0;
    for (; my_double[i] && my_double[i] != '.'; i++);
    i += (my_double[i] == '.');
    my_double[i - 1 + flag_hashtag] = '\0';
    return 0;
}

static int put_zero_precision(int precision, int count)
{
    for (int i = 0; i < precision - count; i++)
        my_putchar('0');
    return 0;
}

static int put_zero(printf_data_t *data, char *my_double,
    int precision, int count)
{
    int size = my_strlen(my_double);
    int flag_zero = flag_in(data->flag, '0');
    int flag_negatif = flag_in(data->flag, '-');
    int field = get_field(data->ap, data->flag, data->field, size);

    if (flag_negatif) {
        my_putstr(1, my_double);
        put_zero_precision(precision, count);
    }
    for (int i = 0; i < field - (size + precision - count); i++) {
        if (flag_zero && !flag_negatif)
            my_putchar('0');
        else
            my_putchar(' ');
    }
    if (!flag_negatif) {
        my_putstr(1, my_double);
        put_zero_precision(precision, count);
    }
    return 0;
}

int specifier_maj_f(printf_data_t *data)
{
    double nbr = va_arg(data->ap, double);
    char *my_double = my_ftoa(nbr);
    int flag_hashtag = flag_in(data->flag, '#');
    int precision = get_precision(data->ap, data->precision, 6);
    int dot_encounter = 0;
    int count = 0;
    int i = 0;

    for (; my_double[i + dot_encounter] && count < precision; i++) {
        if (my_double[i] == '.')
            dot_encounter = 1;
        count += (dot_encounter && my_double[i] != '.');
    }
    handle_zero_precision(my_double, precision, flag_hashtag);
    put_zero(data, my_double, precision, count);
    free(my_double);
    return 0;
}
