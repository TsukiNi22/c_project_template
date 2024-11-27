/*
** EPITECH PROJECT, 2024
** my_putnbr_base.c
** File description:
** Convert the given number in the given base
*/

#include "char.h"
#include "write.h"
#include "error.h"

int my_putnbr_base(unsigned long long nbr, char const *base)
{
    int base_size;

    ERR_D(PTR_ERR, "In: my_putnbr_base", KO, (!base));
    base_size = my_strlen(base);
    ERR_D(UNDEF_ERR, "In: my_putnbr_base", KO, (base_size < 0));
    for (int i = 0; nbr >= 1; i++) {
        my_putchar(base[nbr % base_size]);
        nbr /= base_size;
    }
    return OK;
}
