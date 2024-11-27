/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Make all char in uppercase
*/

#include "define.h"
#include "error.h"

char *my_strupcase(char *str)
{
    ERR_DN(PTR_ERR, "In: my_strupcase", (!str));
    for (int i = 0; str[i]; i++) {
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] = (char) ((int) str[i] - 32);
    }
    return str;
}
