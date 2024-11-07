/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** Make all first char of the worlds in upper case
*/

#include "define.h"
#include "error.h"

char *my_strcapitalize(char *str)
{
    int start_word = 0;
    int c1;
    int c2;
    int c3;

    if (!str)
        err_dispatch_n(PTR_ERR, "In: strcapitalize");
    for (int i = 0; str[i]; i++) {
        c1 = (str[i] >= 'a' && str[i] <= 'z');
        c2 = (str[i] >= 'A' && str[i] <= 'Z');
        c3 = (str[i] >= '0' && str[i] <= '9');
        if ((start_word || i == 0) && c1)
            str[i] = (char) ((int) str[i] - 32);
        if (!start_word && i != 0 && c2)
            str[i] = (char) ((int) str[i] + 32);
        start_word = (!c1 && !c2 && !c3);
    }
    return str;
}
