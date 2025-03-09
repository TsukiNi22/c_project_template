/*
** EPITECH PROJECT, 2025
** boolean.c
** File description:
** 'B' specifier
*/

#include "printf.h"
#include "write.h"
#include "error.h"

int specifiers_boolean(printf_data_t *data)
{
    if (!data)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    if (va_arg(data->ap, i_t)) {
        if (my_printf("%O%Ctrue%R", data->fd, 0, 255, 0) == KO)
            return err_prog(UNDEF_ERR, KO, ERR_INFO);
    } else {
        if (my_printf("%O%Cfalse%R", data->fd, 255, 0, 0) == KO)
            return err_prog(UNDEF_ERR, KO, ERR_INFO);
    }
    return OK;
}
