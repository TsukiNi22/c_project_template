/*
** EPITECH PROJECT, 2024
** specifier_percent.c
** File description:
** Specifier percent
*/

#include "write.h"
#include "printf.h"
#include "error.h"

int specifier_percent(printf_data_t *data)
{
    if (my_putchar('%') == KO)
        return err_dispatch(UNDEF_ERR, "In: specifier_percent", KO);
    return 0;
}
