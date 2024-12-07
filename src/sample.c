/*
** EPITECH PROJECT, 2024
** my_top.c
** File description:
** Sample
*/

#include "macro.h"
#include "sample.h"
#include "error.h"

int sample(int argc, char const *argv[], main_data_t *data)
{
    ERR_D(PTR_ERR, "In: sample", KO, (!data || !argv));
    ERR_D(UNDEF_ERR, "In: sample", KO, (init_data(data) == KO));
    INIT_FLAG(argc, argv, data);
    return OK;
}
