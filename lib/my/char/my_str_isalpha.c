/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** Verif if the given string is only upper case
*/

#include "error.h"

int my_str_isalpha(char const *str)
{
    int c1;
    int c2;

    if (!str)
        return err_dispatch(PTR_ERR, "In: str_isalpha", KO);
    for (int i = 0; str[i]; i++) {
        c1 = (str[i] >= 'A' && str[i] <= 'Z');
        c2 = (str[i] >= 'a' && str[i] <= 'z');
        if (!(c1 || c2))
            return 0;
    }
    return 1;
}
