/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display the given number
*/

#include "char.h"
#include "write.h"
#include "error.h"
#include <stdlib.h>

int my_putnbr(long long nb)
{
    char *my_nb = my_itoa(nb);

    if (!my_nb)
        return err_prog(PTR_ERR, "In: putnbr", KO);
    if (my_putstr(1, my_nb) == KO)
        return err_prog(UNDEF_ERR, "In: putnbr", KO);
    free(my_nb);
    return OK;
}
