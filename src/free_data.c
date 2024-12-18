/*
** EPITECH PROJECT, 2024
** free_data.c
** File description:
** Free data
*/

#include "sample.h"
#include "error.h"
#include <stdlib.h>

int free_data(main_data_t *data)
{
    if (!data)
        return err_prog(PTR_ERR, "In: free_data", EPITECH_ERR);
    free(data);
    return OK;
}
