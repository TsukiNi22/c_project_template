/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display the given number
*/

#include "char.h"
#include "write.h"
#include "include.h"
#include "error.h"

int my_putnbr(long long nb)
{
    char *my_nb = my_itoa(nb);

    if (!my_nb)
        return err_dispatch(PTR_ERR, "In: putnbr", KO);
    if (my_putstr(1, my_nb) == KO)
        return err_dispatch(WRITE_ERR, "In: putnbr", KO);
    free(my_nb);
    return 0;
}
