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
    int res;

    ERR_D(PTR_ERR, "In: my_str_isnum", false, (!str || !char_in));
    for (int i = 0; str[i]; i++) {
        res = my_strfind(char_in, str[i]);
        ERR_D(UNDEF_ERR, "In: my_str_isnum", false, (res == -2));
        if (res == -1)
            return 0;
    }
    return 1;
}
