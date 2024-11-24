/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** Verif if the given string is only lowr case
*/

#include "error.h"
#include <stdbool.h>

bool my_str_islower(char const *str)
{
    ERR_D(PTR_ERR, "In: my_str_islower", false, (!str));
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return false;
    }
    return true;
}
