/*
** EPITECH PROJECT, 2025
** error_system.c
** File description:
** Error print for system version
*/

#include "define.h"
#include "sample.h"
#include "write.h"
#include "error.h"
#include <stdbool.h>

void err_system_v(void *data, char const *info, char const *err)
{
    int res = OK;

    if (data)
        ((main_data_t *) data)->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return;
    res += my_printf("%O%C%s: %C%s.\n", 2,
    192, 192, 192,
    info,
    0, 255, 255,
    err);
    if (res != OK)
        error_error();
}

void *err_system_n(void *data, char const *info, char const *err)
{
    int res = OK;

    if (data)
        ((main_data_t *) data)->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return NULL;
    res += my_printf("%O%C%s: %C%s.\n", 2,
    192, 192, 192,
    info,
    0, 255, 255,
    err);
    if (res != OK)
        error_error();
    return NULL;
}

int err_system(void *data, int to_return, char const *info, char const *err)
{
    int res = OK;

    if (data)
        ((main_data_t *) data)->err_sys = true;
    if (!SYSTEM_PUT_ERROR)
        return to_return;
    res += my_printf("%O%C%s: %C%s.\n", 2,
    192, 192, 192,
    info,
    0, 255, 255,
    err);
    if (res != OK)
        error_error();
    return to_return;
}
