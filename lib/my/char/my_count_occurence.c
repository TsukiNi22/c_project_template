/*
** EPITECH PROJECT, 2024
** my_count_occurence.c
** File description:
** Count the number of c in the given string
*/

#include "error.h"

float count_occurence(char const *str, char const c)
{
    float count = 0;

    if (!str)
        return err_dispatch(PTR_ERR, "In: count_occurence", -1);
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
