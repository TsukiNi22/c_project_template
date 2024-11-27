/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** Comparaison of 2 string a n char
*/

#include "error.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    ERR_D(PTR_ERR, "In: my_strncmp", 1000, (!s1 || !s2));
    for (; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] != s2[i] && i < n)
        return (s1[i] - s2[i]);
    return 0;
}
