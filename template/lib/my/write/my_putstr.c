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
    int len;

    ERR_D(PTR_ERR, "In: putstr", KO, (!str));
    len = my_strlen(str);
    ERR_D(UNDEF_ERR, "In: putstr", KO, (len < 0));
    ERR_D(WRITE_ERR, "In: putstr", KO, (write(output, str, len) != len));
    return OK;
}
