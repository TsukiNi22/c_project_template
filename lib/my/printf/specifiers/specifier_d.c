/*
** EPITECH PROJECT, 2024
** specifier_d.c
** File description:
** Specifier d
*/

#include "char.h"
#include "write.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int put_zero_precision(int size, int precision,
    int field, int flag_negatif)
{
    if (flag_negatif && field > precision)
        return 0;
    for (int i = 0; i < precision - size; i++)
        my_putchar('0');
    return 0;
}

static int call_f4(char *my_nbr, int precision, int field, int flag_negatif)
{
    int size = my_strlen(my_nbr);

    put_zero_precision(size, precision, field, flag_negatif);
    my_putstr(1, my_nbr);
    return 0;
}

static int put_zero(printf_data_t *data, char *my_nbr, int precision)
{
    int size = my_strlen(my_nbr);
    int flag_zero = flag_in(data->flag, '0') * (precision == -1);
    int flag_negatif = flag_in(data->flag, '-');
    int field = get_field(data->ap, data->flag, data->field, size);

    precision += (size + 1) * (precision == -1);
    if (flag_negatif)
        call_f4(my_nbr, precision, field, flag_negatif);
    for (int i = 0; i < field - size * (size >= precision)
        - precision * (precision > size); i++) {
        if (flag_zero && !flag_negatif)
            my_putchar('0');
        else
            my_putchar(' ');
    }
    if (!flag_negatif)
        call_f4(my_nbr, precision, field, flag_negatif);
    return 0;
}

int specifier_d(printf_data_t *data)
{
    int nbr = va_arg(data->ap, int);
    char *my_nbr = my_itoa(nbr);
    int precision = get_precision(data->ap, data->precision, -1);

    put_zero(data, my_nbr, precision);
    return 0;
}
