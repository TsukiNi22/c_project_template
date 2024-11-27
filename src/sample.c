/*
** EPITECH PROJECT, 2024
** my_top.c
** File description:
** Sample
*/

#include "sample.h"
#include "error.h"

int sample(main_data_t *data)
{
    ERR_D(PTR_ERR, "In: sample", KO, (!data));
    ERR_D(UNDEF_ERR, "In: sample", KO, (init_data(data) == KO));
    return OK;
}
