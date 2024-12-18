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
    if (!data || !argv)
        return err_prog(PTR_ERR, "In: sample", KO);
    if (init_data(data) == KO)
        return err_custom("Data initialisation error", KO);
    if (init_flag(argc, argv, data) == KO)
        return err_custom("Flag initialisation error", KO);
    return OK;
}
