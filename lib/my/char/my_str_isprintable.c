/*
** EPITECH PROJECT, 2024
** my_str_isprintable.c
** File description:
** Return if the given string only contain printable char
*/

#include "error.h"
#include <stdbool.h>

bool my_str_isprintable(char const *str)
{
    ERR_D(PTR_ERR, "In: my_str_isprintable", false, (!str));
    for (int i = 0; str[i]; i++) {
        if (!((int) str[i] >= 0 && (int) str[i] <= 127))
            return false;
    }
    return true;
}
