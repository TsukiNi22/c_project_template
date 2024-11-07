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

char *my_convertnbr_base(unsigned long long nbr, char const *base)
{
    char *my_nbr;
    int base_size = my_strlen(base);
    int size;

    if (base_size < 0)
        return err_dispatch_n(PTR_ERR, "In: putnbr_base 1");
    size = get_size(nbr, base_size);
    my_nbr = malloc(sizeof(char) * size + 1);
    if (!my_nbr)
        return err_dispatch_n(MALLOC_ERR, "In: putnbr_base 1");
    my_calloc_str(my_nbr, size + 1);
    for (int i = 0; nbr >= 1; i++) {
        my_nbr[size - i - 1] = base[nbr % base_size];
        nbr /= base_size;
    }
    return my_nbr;
}
