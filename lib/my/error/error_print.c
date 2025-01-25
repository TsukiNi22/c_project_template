/*
** EPITECH PROJECT, 2025
** error_handling.c
** File description:
** Error handling
*/

#include "write.h"
#include "error.h"
#include <stdbool.h>

void error_error(void)
{
    my_putstr(2, "\n");
    my_putstr(2, "---------------------ERROR---------------------");
    my_putstr(2, ERROR_MSG);
    my_putstr(2, "---------------------ERROR---------------------");
    my_putstr(2, "\n\n");
}

void print_error(int error_number)
{
    int res = 0;

    if (!PUT_ERROR)
        return;
    res += my_putstr(2, "\n\n");
    res += my_putstr(2, "-------------\033[31m[ERROR]\033[0m------------");
    res += my_putstr(2, "\n");
    res += dispatch(error_number);
    res += my_putstr(2, "\n");
    res += my_putstr(2, "--------------------------------");
    res += my_putstr(2, "\n\n");
    if (res < 0)
        error_error();
}

void print_error_info(char *error_info, bool custom)
{
    int res = 0;

    if (!error_info) {
        error_error();
        return;
    }
    res += my_putstr(2, "\n\n");
    if (custom)
        res += my_putstr(2, "-------------\033[34m[INFO]\033[0m-------------");
    else
        res += my_putstr(2, "-------------\033[36m[INFO]\033[0m-------------");
    res += my_putstr(2, "\n");
    res += my_putstr(2, error_info);
    res += my_putstr(2, "\n");
    res += my_putstr(2, "--------------------------------");
    res += my_putstr(2, "\n\n");
    if (res < 0)
        error_error();
}
