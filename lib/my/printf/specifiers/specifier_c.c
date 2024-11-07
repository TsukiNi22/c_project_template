/*
** EPITECH PROJECT, 2024
** specifier_c.c
** File description:
** Specifier c
*/

#include "write.h"
#include "printf.h"
#include "include.h"
#include "error.h"

int specifier_c(printf_data_t *data)
{
    char c = va_arg(data->ap, int);

    if (my_putchar(c) == KO)
        return err_dispatch(UNDEF_ERR, "In: specifier_c", KO);
    return 0;
}
