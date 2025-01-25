/*
** EPITECH PROJECT, 2025
** error_prog.c
** File description:
** Error handling
*/

#include "write.h"
#include "define.h"
#include "error.h"
#include <stdbool.h>

void err_prog_v(int error_number, char *error_info)
{
    if (!PUT_ERROR)
        return;
    print_error_info(error_info, false);
    print_error(error_number);
}

void *err_prog_n(int error_number, char *error_info)
{
    if (!PUT_ERROR)
        return NULL;
    print_error_info(error_info, false);
    print_error(error_number);
    return NULL;
}

int err_prog(int error_number, char *error_info, int to_return)
{
    if (!PUT_ERROR)
        return to_return;
    print_error_info(error_info, false);
    print_error(error_number);
    return to_return;
}
