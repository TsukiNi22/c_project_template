/*
** EPITECH PROJECT, 2024
** my_printf_dispatch.c
** File description:
** This file call the apropiate function
** for the specifier after the identifier
*/

#include "char.h"
#include "printf.h"
#include "error.h"

static const int (*array[])(printf_data_t *) = {
    &specifier_d,
    &specifier_i,
    &specifier_o,
    &specifier_u,
    &specifier_x,
    &specifier_maj_x,
    &specifier_e,
    &specifier_maj_e,
    &specifier_f,
    &specifier_maj_f,
    &specifier_g,
    &specifier_maj_g,
    &specifier_c,
    &specifier_s,
    &specifier_p,
    &specifier_percent
};

int printf_dispatch(printf_data_t *data)
{
    char *ptr_start;
    int index;

    if (!data || !(data->specifiers))
        return err_dispatch(PTR_ERR, "In: printf_dispatch 1", KO);
    ptr_start = my_strstr(SPECIFIERS, data->specifiers);
    if (!ptr_start)
        return err_dispatch(PTR_ERR, "In: printf_dispatch 2", KO);
    index = my_get_index(SPECIFIERS, ptr_start[0]);
    if (index < 0 || !array[index])
        return err_dispatch(PTR_ERR, "In: printf_dispatch 3", KO);
    if (array[index](data) == KO)
        return err_dispatch(UNDEF_ERR, "In: printf_dispatch", KO);
    return 0;
}
