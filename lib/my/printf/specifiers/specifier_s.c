/*
** EPITECH PROJECT, 2024
** specifier_s.c
** File description:
** Specifier s
*/

#include "char.h"
#include "write.h"
#include "memory.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int set_space(char *str, int field, int precision, int flag_negate)
{
    int size = precision + (field - precision) * (field > precision);

    for (int i = 0; i < field - precision; i++) {
        if (flag_negate)
            str[size - i - 1] = ' ';
        else
            str[i] = ' ';
    }
    return 0;
}

static int set_str(char *new_str, char *str, int field, int precision)
{
    int flag_negate = (field < 0);
    int size;

    field *= (1 - 2 * (flag_negate));
    size = precision + (field - precision) * (field > precision);
    for (int i = 0; str[i] && i < precision; i++) {
        if (flag_negate)
            new_str[i] = str[i];
        if (!flag_negate)
            new_str[size - precision + i] = str[i];
    }
    return 0;
}

static char *set_str_null(int precision)
{
    if (precision >= 6)
        return "(null)\0";
    return "\0";
}

static int g_default(char *str)
{
    return my_strlen(str) + 7 * (!str);
}

static int my_clean(char *str)
{
    free(str);
    return 0;
}

int specifier_s(printf_data_t *data)
{
    char *str = va_arg(data->ap, char *);
    char *new_str;
    int flag_negate_field = flag_in(data->flag, '-');
    int field = get_field(data->ap, data->flag, data->field, 0);
    int precision = get_precision(data->ap, data->precision, g_default(str));
    int signe = (field > precision);
    int size = precision + (field - precision) * signe;

    if (!str)
        str = set_str_null(precision);
    new_str = my_malloc(size + 1, sizeof(char));
    if (field > precision)
        set_space(new_str, field, precision, flag_negate_field);
    set_str(new_str, str, field * (1 - 2 * flag_negate_field), precision);
    if (field == 0 && precision == 0)
        new_str[0] = '\0';
    if (my_putstr(1, new_str) == KO)
        return err_dispatch(UNDEF_ERR, "In: specifier_s", KO);
    return my_clean(new_str);
}
