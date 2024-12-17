/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** Error handling
*/

#include "write.h"
#include "define.h"
#include "error.h"

void err_system_v(char *error_info)
{
    if (!SYSTEM_PUT_ERROR)
        return;
    if (my_putstr(2, error_info) == KO)
        error_error();
}

void *err_system_n(char *error_info)
{
    if (!SYSTEM_PUT_ERROR)
        return NULL;
    if (my_putstr(2, error_info) == KO)
        error_error();
    return NULL;
}

int err_system(char *error_info)
{
    if (!SYSTEM_PUT_ERROR)
        return KO;
    if (my_putstr(2, error_info) == KO)
        error_error();
    return KO;
}
