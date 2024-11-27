/*
** EPITECH PROJECT, 2024
** my_putnbr_base.c
** File description:
** Convert the given number in the given base
*/

#include "char.h"
#include "write.h"
#include "memory.h"
#include "error.h"

static int get_size(unsigned long long nbr, int base_size)
{
    int size = 0;

    for (; nbr >= 1; size++)
        nbr /= base_size;
    return size;
}

char *my_convertnbr_base(unsigned long long nbr, char const *base)
{
    char *my_nbr;
    int base_size;
    int size;

    ERR_DN(PTR_ERR, "In: my_putnbr_base", (!base));
    base_size = my_strlen(base);
    ERR_DN(UNDEF_ERR, "In: my_putnbr_base 1", (base_size < 0));
    size = get_size(nbr, base_size);
    ERR_DN(UNDEF_ERR, "In: my_putnbr_base 2",
    (my_malloc_c(&my_nbr, size + 1) == KO));
    for (int i = 0; nbr >= 1; i++) {
        my_nbr[size - i - 1] = base[nbr % base_size];
        nbr /= base_size;
    }
    return my_nbr;
}
