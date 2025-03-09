/*
** EPITECH PROJECT, 2025
** error_print.c
** File description:
** Print the error message (information)
*/

#include "write.h"
#include "error.h"
#include <unistd.h>
#include <stdbool.h>

void error_error(void)
{
    write(2, "\n", 1);
    write(2, "---------------------ERROR---------------------\n", 48);
    write(2, "Error: An Error have ocured in the error return.\n", 49);
    write(2, "---------------------ERROR---------------------\n", 48);
    write(2, "\n", 1);
}

void print_error_custom(char *info, err_t err)
{
    int res = OK;

    if (!info) {
        error_error();
        return;
    }
    res += my_printf("%O%S\n"
    "-------------\033[31m[ERROR]%R%S------------%R"
    "\n"
    "%C%s, %s, line %d: %C%s%R%S"
    "\n"
    "--------------------------------"
    "\n\n%R", 2,
    192, 192, 192,
    err.file, err.func, err.line,
    0, 255, 255,
    info);
    if (res != OK)
        error_error();
}

void print_error_prog(error_code_t code, err_t err)
{
    int res = OK;

    res += my_printf("%O%S\n"
    "-------------\033[31m[ERROR]%R%S------------%R"
    "\n"
    "%C%s, %s, line %d: %C", 2,
    192, 192, 192,
    err.file, err.func, err.line,
    0, 255, 255);
    res += dispatch(code);
    res += my_printf("%O%R%S"
    "\n"
    "--------------------------------"
    "\n\n%R", 2);
    if (res != OK)
        error_error();
}
