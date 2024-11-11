/*
** EPITECH PROJECT, 2024
** specifier_maj_x.c
** File description:
** Specifier X
*/

#include "char.h"
#include "math.h"
#include "write.h"
#include "memory.h"
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
    int c = (my_nbr[my_strlen(my_nbr) + 1] == '1' ||
    my_nbr[my_strlen(my_nbr) + 1] == '-');
    int i = 0;

    size += c;
    if (c)
        my_putstr(1, "0x");
    put_zero_precision(size, precision, field, flag_negatif);
    my_putstr(1, my_nbr);
    return 0;
}

static int verif_base(char *nbr, int precision, int field, int flag)
{
    int size = my_strlen(nbr);

    if (nbr[size + 1] == '1'
        && field - size * (size >= precision)
        - precision * (precision > size) > 0
        && flag) {
        my_putstr(1, "0x");
        nbr[size + 1] = '-';
    }
    return 0;
}

static int put(int c)
{
    if (c)
        my_putchar('0');
    else
        my_putchar(' ');
    return 0;
}

static int put_zero(printf_data_t *data, char *my_nbr, int precision)
{
    int size = my_strlen(my_nbr);
    int flag_zero = flag_in(data->flag, '0') * (precision == -1);
    int flag_negatif = flag_in(data->flag, '-');
    int c = (my_nbr[size + 1] == '1' && !flag_zero);
    int field = get_field(data->ap, data->flag, data->field, size + c);

    size += c * 2;
    precision += (size + 1) * (precision == -1);
    if (flag_negatif)
        call_f4(my_nbr, precision, field, flag_negatif);
    else
        verif_base(my_nbr, precision, field, flag_zero && !flag_negatif);
    for (int i = 0; i < field - size * (size >= precision)
        - precision * (precision > size); i++)
        put(flag_zero && !flag_negatif);
    if (!flag_negatif)
        call_f4(my_nbr, precision, field, flag_negatif);
    return 0;
}

int specifier_maj_x(printf_data_t *data)
{
    int nbr = va_arg(data->ap, int);
    char *my_nbr = my_convertnbr_base((unsigned int) nbr, "0123456789ABCDEF");
    int precision = get_precision(data->ap, data->precision, -1);
    int flag_hashtag = flag_in(data->flag, '#');
    int size = my_strlen(my_nbr);

    my_nbr = my_realloc(my_nbr, 2, my_strlen(my_nbr), sizeof(char));
    my_nbr[size + 1] = flag_hashtag + 48;
    put_zero(data, my_nbr, precision);
    return 0;
}
