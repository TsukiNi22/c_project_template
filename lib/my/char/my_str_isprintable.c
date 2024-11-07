/*
** EPITECH PROJECT, 2024
** my_str_isprintable.c
** File description:
** Return if the given string only contain printable char
*/

#include "error.h"

int my_str_isprintable(char const *str)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: str_isprintable", KO);
    for (int i = 0; str[i]; i++) {
        if (!((int) str[i] >= 0 && (int) str[i] <= 127))
            return 0;
    }
    return 1;
}
