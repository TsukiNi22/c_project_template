/*
** EPITECH PROJECT, 2025
** init_matrice.c
** File description:
** Setup a matrice of x, y size
*/

#include "define.h"
#include "matrice.h"
#include "error.h"
#include <stdlib.h>

int free_matrice(matrice_t **matrice)
{
    if (!matrice || !(*matrice) || !(*matrice)->matrice)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    for (int y = 0; y < (*matrice)->y; y++) {
        if (!((*matrice)->matrice[y]))
            return err_prog(PTR_ERR, KO, ERR_INFO);
        free((*matrice)->matrice[y]);
    }
    free((*matrice)->matrice);
    free((*matrice));
    *matrice = NULL;
    return OK;
}
