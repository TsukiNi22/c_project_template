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

    if (!str)
        return err_prog(PTR_ERR, "In: my_count_occurence", KO);
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
