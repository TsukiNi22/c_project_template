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
    if (!str)
        return err_dispatch(PTR_ERR, "In: putstr", KO);
    for (int i = 0; str[i]; i++) {
        if (write(output, &str[i], 1) != 1)
            return err_dispatch(WRITE_ERR, "In: putstr", KO);
    }
    return 0;
}
