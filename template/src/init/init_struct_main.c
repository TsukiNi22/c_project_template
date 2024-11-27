/*
** EPITECH PROJECT, 2024
** init_struct_main.c
** File description:
** Init struct for main data
*/

#include "sample.h"
#include "error.h"

int init_struct_main(main_data_t *data)
{
    ERR_D(PTR_ERR, "In: init_struct_main", KO, (!data));
    return OK;
}