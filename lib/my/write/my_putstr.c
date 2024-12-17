/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** Write a str
*/

#include "char.h"
#include "error.h"
#include <unistd.h>

int my_putstr(int output, char const *str)
{
    int len = 0;

    if (!str)
        return err_prog(PTR_ERR, "In: putstr", KO);
    len = my_strlen(str);
    if (len < 0)
        return err_prog(UNDEF_ERR, "In: putstr", KO);
    if (write(output, str, len) != len)
        return err_prog(WRITE_ERR, "In: putstr", KO);
    return OK;
}
