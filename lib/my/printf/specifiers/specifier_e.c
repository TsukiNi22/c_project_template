/*
** EPITECH PROJECT, 2024
** specifier_e.c
** File description:
** Specifier e
*/

#include "char.h"
#include "math.h"
#include "write.h"
#include "memory.h"
#include "printf.h"
#include "macro.h"
#include "include.h"
#include "error.h"

static int set_e(char *str, long double e, int ret)
{
    char *power_str;
    int power = e * (1 - 2 * (e < 0)) + (e < 0) + ret;
    int i = my_strlen(str);

    str[i] = 'e';
    str[i + 1] = '+' + 2 * (e < 0);
    if (power < 10)
        str[i + 2] = '0';
    power_str = my_itoa(power);
    my_strcat(str, power_str);
    free(power_str);
    return 0;
}

static int my_round(char *my_double, char *str, int i1, int i2)
{
    int ret;

    i2 += (my_double[i2] == '.');
    ret = (my_double[i2] && my_double[i2] >= '5');
    while (i1 > 0 && ret && str[i1 - 1] && my_double[i2]) {
        str[i1 - 1] += ret;
        if (str[i1 - 1] > '9') {
            ret = 1;
            str[i1 - 1] = '0';
        } else
            ret = 0;
        i1--;
        i1 -= (i1 > 0 && str[i1 - 1] == '.');
    }
    if (i1 == 0 && ret == 1)
        str[0] = '1';
    return ret;
}

static int handle_zero_precision(char *str, char *my_double,
    double nbr, int precision)
{
    str[precision + 2 + (nbr < 0)] = '\0';
    if (precision != 0)
        return 0;
    if (str[0] == '!') {
        str[0] = my_double[0];
        str[1] = '.';
        str[2] = '\0';
    } else {
        str[0] = my_double[0];
        str[1] = '\0';
    }
    return 0;
}

static int set_str(char *str, double nbr, long double e, int precision)
{
    char *my_double = my_ftoa(nbr);
    int count = 0;
    int size;
    int dot_d = 0;
    int dot_str = 0;

    str[1 + (nbr < 0)] = '.';
    for (int i = 0; my_double[i + dot_d] && count < precision; i++) {
        dot_d += (my_double[i] == '.');
        dot_str += (i == 1 + (nbr < 0));
        str[i + dot_str] = my_double[i + dot_d];
        count += (dot_str && my_double[i] != '.');
    }
    handle_zero_precision(str, my_double, nbr, precision);
    size = my_strlen(str);
    dot_str = my_round(my_double, str, size + dot_str - 1, size + dot_d - 1);
    for (int i = 0; i < precision - count; i++)
        str[size + i] = '0';
    set_e(str, e, dot_str);
    return 0;
}

static int get_count(char *my_double, int precision)
{
    int dot_encounter = 0;
    int count = 0;

    for (int i = 0; my_double[i + dot_encounter] && count < precision; i++) {
        if (my_double[i] == '.')
            dot_encounter = 1;
        count += (dot_encounter && my_double[i] != '.');
    }
    return count;
}

static int put_zero(printf_data_t *data, char *my_double, int precision)
{
    int size = my_strlen(my_double);
    int flag_zero = flag_in(data->flag, '0');
    int flag_negatif = flag_in(data->flag, '-');
    int field = get_field(data->ap, data->flag, data->field, size);
    int count = get_count(my_double, precision);

    if (flag_negatif)
        my_putstr(1, my_double);
    for (int i = 0; i < field - (size + precision - count); i++) {
        if (flag_zero && !flag_negatif)
            my_putchar('0');
        else
            my_putchar(' ');
    }
    if (!flag_negatif)
        my_putstr(1, my_double);
    return 0;
}

int specifier_e(printf_data_t *data)
{
    double nbr = va_arg(data->ap, double);
    long double e = my_log(ABS(nbr), 10);
    int flag_hastag = flag_in(data->flag, '#');
    int precision = get_precision(data->ap, data->precision, 6);
    char *str = my_malloc(precision + 2 + 4 + (e >= 100), sizeof(char));

    for (; (nbr < 1 && nbr > 0) || (nbr < 0 && nbr > -1); nbr *= 10);
    if (flag_hastag)
        str[0] = '!';
    set_str(str, nbr, e, precision);
    put_zero(data, str, precision);
    free(str);
    return 0;
}
