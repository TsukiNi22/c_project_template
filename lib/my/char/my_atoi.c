/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** Vous savait je ne pense pas qu il y ait de bonne ou de mauvaise descrition
** pour moi la vie c est avant tous des fonctions...
*/

#include "math.h"
#include "char.h"
#include "memory.h"
#include "define.h"
#include "include.h"
#include "error.h"

long long my_atoi(const char *str)
{
    int array_size = my_strlen(str);
    bool negatif;
    long long my_int = 0;
    long long mult;

    ERR_D(PTR_ERR, "In: my_atoi", 0, (!str || array_size < 0));
    negatif = (str[0] && str[0] == '-');
    for (int i = negatif; str[i]; i++) {
        mult = my_pow(10, array_size - i - negatif);
        my_int += ((long long) str[i] - 48) * mult;
    }
    if (negatif)
        my_int *= -1;
    ERR_D(OVERFLOW, "In: my_atoi", 0,
    ((!negatif && my_int < 0) || (negatif && my_int >= 0)));
    return my_int;
}
