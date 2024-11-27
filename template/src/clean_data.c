/*
** EPITECH PROJECT, 2024
** clean_data.c
** File description:
** Clean data
*/

#include "sample.h"
#include "error.h"
#include <stdlib.h>

int clean_data(main_data_t *data)
{
    ERR_D(PTR_ERR, "In: clean_data", EPITECH_ERR, (!data));
    free(data);
    return OK;
}
