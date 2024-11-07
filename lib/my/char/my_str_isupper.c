/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** Verif if the given string is only upper case
*/

#include "error.h"

int my_str_isupper(char const *str)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: str_isupper", KO);
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return 0;
    }
    return 1;
}
