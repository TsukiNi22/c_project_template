/*
** EPITECH PROJECT, 2024
** my_printf_identifier_encounter.c
** File description:
** Get the information after the identifier and setup it in a struc
*/

#include "char.h"
#include "printf.h"
#include "include.h"
#include "define.h"
#include "error.h"

static int data_clean(printf_data_t *data)
{
    if (!data)
        return err_dispatch(PTR_ERR, "In: printf_identif 4.1", KO);
    if (data->flag)
        free(data->flag);
    if (data->field)
        free(data->field);
    if (data->precision)
        free(data->precision);
    if (data->lenght_modifier)
        free(data->lenght_modifier);
    if (data->specifiers)
        free(data->specifiers);
    return 0;
}

static int count_star(char *str)
{
    int count = 0;

    if (!str)
        return err_dispatch(PTR_ERR, "In: printf_identif 2.1.1", KO);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*')
            count++;
    }
    return count;
}

static int verif_star(char *flag, char *field, char *precision)
{
    int count_field = 0;
    int count_pre = 0;

    if (!flag || !field || !precision)
        return err_dispatch(PTR_ERR, "In: printf_identif 2.1", KO);
    for (int i = 0; flag[i]; i++) {
        if (flag[i] == '*' && i == my_strlen(flag) - 1
            && my_strcmp(field, "") == 0)
            return 0;
        if (flag[i] == '*')
            return -1;
    }
    count_field = count_star(field);
    count_pre = count_star(precision);
    if (count_field > 1 || (count_field == 1 && my_strcmp(field, "*") != 0) ||
        count_pre > 1 || (count_pre == 1 && my_strcmp(precision, ".*") != 0))
        return -1;
    return 0;
}

int identifier_encouter(printf_data_t *data, int *i)
{
    int start = *i;

    if (!(data->str) || !i)
        return err_dispatch(PTR_ERR, "In: printf_identifier 1", KO);
    data->flag = get_info_single_char(data->str, FLAGS, i, 0);
    data->field = get_info_single_char(data->str, FIELD_WIDHT, i, 0);
    data->precision = get_info_single_char(data->str, PRECISION, i, 0);
    data->lenght_modifier = get_info_mult_char(data->str, MODIFIER, i, 0);
    data->specifiers = get_info_single_char(data->str, SPECIFIERS, i, 1);
    if (!(data->flag) || !(data->field) || !(data->precision) ||
        !(data->lenght_modifier) || !(data->specifiers))
        return err_dispatch(UNDEF_ERR, "In: printf_identif 2", KO);
    if (my_strcmp(data->specifiers, "") == 0 ||
        verif_star(data->flag, data->field, data->precision) != 0) {
        *i = start - 1;
        return verif_star(data->flag, data->field, data->precision);
    }
    if (printf_dispatch(data) == KO)
        return err_dispatch(UNDEF_ERR, "In: printf_identif 3", KO);
    return data_clean(data);
}
