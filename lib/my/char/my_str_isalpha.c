/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** Verif if the given string is only upper case
*/

#include "error.h"
#include <stdbool.h>

bool my_str_isalpha(char const *str)
{
    bool c1 = false;
    bool c2 = false;

    if (!str)
        return err_prog(PTR_ERR, "In: my_str_isalpha", false);
    for (int i = 0; str[i]; i++) {
        c1 = (str[i] >= 'A' && str[i] <= 'Z');
        c2 = (str[i] >= 'a' && str[i] <= 'z');
        if (!(c1 || c2))
            return false;
    }
    return true;
}
