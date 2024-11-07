/*
** EPITECH PROJECT, 2024
** my_itoa.c
** File description:
** Return the given int in an array
*/

#include "char.h"
#include "memory.h"
#include "include.h"
#include "error.h"

static char *get_str_from_nbr(long long n, int negatif)
{
    char *str;
    long long diviseur = 1;
    long long nbis = 0;
    long long nb;
    int size = 0;
    int i = negatif;

    for (; n / diviseur >= 10; diviseur *= 10);
        size++;
    str = malloc(sizeof(char) * (size + negatif));
    my_calloc_str(str, size + negatif);
    str[0] = '-' * negatif;
    for (; diviseur > 0; diviseur /= 10) {
        nb = (n / diviseur) - nbis;
        nbis = (n / diviseur) * 10;
        str[i] = nb + 48 + (n == LLONG_MAX && diviseur == 1 && negatif);
        i++;
    }
    str[i] = '\0';
    return str;
}

char *my_itoa(long long n)
{
    int negatif = (n < 0);

    n *= 1 - 2 * negatif;
    if (n == LLONG_MIN)
        n = LLONG_MAX;
    return get_str_from_nbr(n, negatif);
}
