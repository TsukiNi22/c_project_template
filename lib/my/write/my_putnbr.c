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

    ERR_D(PTR_ERR, "In: putnbr", KO, (!my_nb));
    ERR_D(UNDEF_ERR, "In: putnbr", KO, (my_putstr(1, my_nb) == KO));
    free(my_nb);
    return OK;
}
