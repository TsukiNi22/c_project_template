/*
** EPITECH PROJECT, 2024
** my_strcomp.c
** File description:
** Comparaison of 2 string
*/

#include "error.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    ERR_D(PTR_ERR, "In: my_strcmp", 1000, (!s1 || !s2));
    for (; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
    return 0;
}
