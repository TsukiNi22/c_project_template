/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** Error handling
*/

#include "write.h"
#include "define.h"
#include "error.h"

static int text_shape(int n)
{
    if (n == -1) {
        text_shape(3);
        text_shape(1);
        text_shape(2);
    }
    if (n == -2) {
        text_shape(2);
        text_shape(1);
        text_shape(3);
    }
    if (n == 0)
        return my_putstr(2, "---------------------KO---------------------");
    if (n == 1)
        return my_putstr(2, "----------------------------------------------");
    if (n == 2)
        return my_putstr(2, "\n");
    if (n == 3)
        return my_putstr(2, "\n\n");
    return KO;
}

static int dispatch_1(int error_number)
{
    if (!PUT_ERROR)
        return OK;
    if (error_number == OVERFLOW)
        return my_putstr(2, OVERFLOW_MSG);
    if (error_number == PTR_ERR)
        return my_putstr(2, PTR_MSG);
    if (error_number == MALLOC_ERR)
        return my_putstr(2, MALLOC_MSG);
    if (error_number == WRITE_ERR)
        return my_putstr(2, WRITE_MSG);
    if (error_number == ARGC_NBR_ERR)
        return my_putstr(2, ARGC_NBR_MSG);
    if (error_number == ARGV_ERR)
        return my_putstr(2, ARGV_MSG);
    if (error_number == OP_FILE_ERR)
        return my_putstr(2, OP_FILE_MSG);
    return KO;
}

static void error_error(void)
{
    text_shape(2);
    my_putstr(2, ERROR_MSG);
    text_shape(2);
    text_shape(0);
    text_shape(3);
}

static int print_error(int error_number, int to_return)
{
    int res = 0;

    if (!PUT_ERROR)
        return to_return;
    res += text_shape(3);
    res += text_shape(1);
    res += text_shape(2);
    if (error_number == ERROR_ERR)
        res += my_putstr(2, ERROR_MSG);
    if (error_number == UNDEF_ERR)
        res += my_putstr(2, UNDEF_MSG);
    res += dispatch_1(error_number);
    res += text_shape(2);
    res += text_shape(1);
    res += text_shape(3);
    if (res < 0)
        error_error();
    return to_return;
}

static int print_error_info(char *error_info)
{
    if (error_info) {
        text_shape(-1);
        my_putstr(2, error_info);
        text_shape(-2);
    } else {
        error_error();
        return KO;
    }
    return OK;
}

void err_dispatch_v(int error_number, char *error_info)
{
    if (!PUT_ERROR)
        return;
    print_error_info(error_info);
    print_error(error_number, KO);
}

void *err_dispatch_n(int error_number, char *error_info)
{
    if (!PUT_ERROR)
        return NULL;
    print_error_info(error_info);
    print_error(error_number, KO);
    return NULL;
}

int err_dispatch(int error_number, char *error_info, int to_return)
{
    if (!PUT_ERROR)
        return to_return;
    print_error_info(error_info);
    return print_error(error_number, to_return);
}

int err_custom(char *error_info, int to_return)
{
    if (!CUSTOM_PUT_ERROR)
        return to_return;
    print_error_info(error_info);
    return to_return;
}
