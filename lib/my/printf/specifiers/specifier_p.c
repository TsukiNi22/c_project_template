/*
** EPITECH PROJECT, 2024
** specifier_p.c
** File description:
** Specifier p
*/

#include "write.h"
#include "printf.h"
#include "include.h"
#include "error.h"

int specifier_p(printf_data_t *data)
{
    unsigned long long ptr = (unsigned long long) va_arg(data->ap, void *);

    if (my_putstr(1, "0x") == KO
        || my_putnbr_base(ptr, "0123456789abcdef") == KO)
        return err_dispatch(UNDEF_ERR, "In: specifier_p", KO);
    return 0;
}
