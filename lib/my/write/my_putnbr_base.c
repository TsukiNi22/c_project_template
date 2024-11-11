/*
** EPITECH PROJECT, 2024
** my_putnbr_base.c
** File description:
** Convert the given number in the given base
*/

#include "char.h"
#include "write.h"
#include "memory.h"
#include "include.h"
#include "error.h"

static int get_size(unsigned long long nbr, int base_size)
{
    int size = 0;

    for (; nbr >= 1; size++)
        nbr /= base_size;
    return size;
}

int my_putnbr_base(unsigned long long nbr, char const *base)
{
    char *my_nbr;
    int base_size;
    int size;

    ERR_D(PTR_ERR, "In: my_putnbr_base 1", KO, (!base));
    base_size = my_strlen(base);
    ERR_D(UNDEF_ERR, "In: my_putnbr_base 1", KO, (base_size < 0));
    size = get_size(nbr, base_size);
    my_nbr = my_malloc(size + 1, sizeof(char));
    ERR_D(UNDEF_ERR, "In: my_putnbr_base 2", KO, (!my_nbr));
    for (int i = 0; nbr >= 1; i++) {
        my_nbr[size - i - 1] = base[nbr % base_size];
        nbr /= base_size;
    }
    ERR_D(UNDEF_ERR, "In: my_putnbr_base 3", KO, (my_putstr(1, my_nbr) == KO));
    free(my_nbr);
    return OK;
}
