/*
** EPITECH PROJECT, 2025
** init_data.c
** File description:
** Init the main data
*/

#include "sample.h"
#include "error.h"

int init_data(main_data_t *data)
{
    if (!data)
        return err_prog(PTR_ERR, "In: sample", KO);
    if (init_struct_main(data) == KO)
        return err_prog(UNDEF_ERR, "In: sample", KO);
    return OK;
}
