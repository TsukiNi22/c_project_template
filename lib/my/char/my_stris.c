/*
** EPITECH PROJECT, 2024
** my_str_isnum.c
** File description:
** Verif if the given string is only number
*/

#include "char.h"
#include "error.h"
#include <stdbool.h>

int my_str_is(char const *str, char const *char_in)
{
    int res = 0;

    if (!str || !char_in)
        return err_prog(PTR_ERR, "In: my_str_isnum", false);
    for (int i = 0; str[i]; i++) {
        res = my_strfind(char_in, str[i]);
        if (res == -2)
            return err_prog(UNDEF_ERR, "In: my_str_isnum", false);
        if (res == -1)
            return 0;
    }
    return 1;
}
