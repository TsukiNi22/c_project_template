/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** Make all first char of the worlds in upper case
*/

#include "define.h"
#include "include.h"
#include "error.h"

char *my_strcapitalize(char *str)
{
    bool start_word = 0;
    bool c1;
    bool c2;
    bool c3;

    ERR_DN(PTR_ERR, "In: my_strcapitalize",(!str));
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
