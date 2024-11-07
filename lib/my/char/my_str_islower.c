/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** Verif if the given string is only lowr case
*/

#include "error.h"

int my_str_islower(char const *str)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: str_islower", KO);
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
    }
    return 1;
}
