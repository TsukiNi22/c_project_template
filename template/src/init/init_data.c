/*
** EPITECH PROJECT, 2024
** init_data.c
** File description:
** Init the main data
*/

#include "sample.h"
#include "error.h"

int init_data(main_data_t *data)
{
    ERR_D(PTR_ERR, "In: sample", KO, (!data));
    ERR_D(UNDEF_ERR, "In: sample", KO, (init_struct_main(data) == KO));
    return OK;
}
