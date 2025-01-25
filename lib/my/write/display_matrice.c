/*
** EPITECH PROJECT, 2025
** str_to_matrice.c
** File description:
** Convert a str to a quare matrice
*/

#include "my_math.h"
#include "string.h"
#include "write.h"
#include "matrice.h"
#include "error.h"

int display_matrice(matrice_t *matrice)
{
    if (!matrice)
        return err_prog(PTR_ERR, "In: display_matrice", KO);
    my_putchar('\n');
    for (int i = 0; i < matrice->y; i++) {
        for (int j = 0; j < matrice->x; j++) {
            my_putchar('[');
            my_putnbr(matrice->matrice[i][j]);
            my_putstr(1, "]\t");
        }
        my_putchar('\n');
    }
    return OK;
}
