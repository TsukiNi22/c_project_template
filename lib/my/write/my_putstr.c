/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** Write a str
*/

#include "include.h"
#include "error.h"

int my_putstr(int output, char const *str)
{
    ERR_D(PTR_ERR, "In: putstr", KO, (!str));
    for (int i = 0; str[i]; i++)
        ERR_D(WRITE_ERR, "In: putstr", KO, (write(output, &str[i], 1) != 1));
    return OK;
}
