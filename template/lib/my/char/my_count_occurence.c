/*
** EPITECH PROJECT, 2024
** my_count_occurence.c
** File description:
** Count the number of c in the given string
*/

#include "error.h"

int count_occurence(char const *str, char const c)
{
    int count = 0;

    ERR_D(PTR_ERR, "In: my_count_occurence", KO, (!str));
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
