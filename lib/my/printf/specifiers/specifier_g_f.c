/*
** EPITECH PROJECT, 2024
** specifier_g_f.c
** File description:
** Specifier g f
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

static int destroy_zero(char *my_double, int flag_hashtag)
{
    if (flag_hashtag)
        return 0;
    for (int i = my_strlen(my_double) - 1; my_double[i] && i >= 0
        && (my_double[i] == '0' || my_double[i] == '.'); i++)
        my_double[i] = '\0';
    return 0;
}

static int get_count(char *my_double, int precision)
{
    int dot_encounter = 0;
    int count = 0;
    int i = 0;

    for (; my_double[i + dot_encounter] && count < precision; i++) {
        if (my_double[i] == '.')
            dot_encounter = 1;
        count += (my_double[i] != '.');
    }
    return count;
}

static int put_result(char *my_double, int flag_hashtag,
    int precision, int count)
{
    my_putstr(1, my_double);
    for (int i = 0; flag_hashtag && i < precision - count; i++)
        my_putchar('0');
    return 0;
}

static int put_zero_precision(printf_data_t *data, char *my_double,
    int precision, int i)
{
    int flag_negatif = flag_in(data->flag, '-');
    int flag_hashtag = flag_in(data->flag, '#');
    int flag_zero = flag_in(data->flag, '0');
    int size = my_strlen(my_double);
    int field = get_field(data->ap, data->flag, data->field, size);
    int count = get_count(my_double, precision);

    if (flag_negatif)
        put_result(my_double, flag_hashtag, precision, count);
    for (int i = 0; i < field - size - 1; i++) {
        if (flag_zero && !flag_negatif)
            my_putchar('0');
        else
            my_putchar(' ');
    }
    if (!flag_negatif)
        put_result(my_double, flag_hashtag, precision, count);
    return 0;
}

int specifier_g_f(printf_data_t *data, int precision, long double nbr)
{
    char *my_double = my_ftoa(nbr);
    int flag_hashtag = flag_in(data->flag, '#');
    int dot_encounter = 0;
    int count = 0;
    int i = 0;

    for (; my_double[i + dot_encounter] && count < precision; i++) {
        if (my_double[i] == '.')
            dot_encounter = 1;
        count += (my_double[i] != '.');
    }
    handle_zero_precision(my_double, precision, flag_hashtag);
    destroy_zero(my_double, flag_hashtag);
    put_zero_precision(data, my_double, precision, i);
    free(my_double);
    return 0;
}
