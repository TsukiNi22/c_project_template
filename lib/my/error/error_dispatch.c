/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** Error handling
*/

#include "write.h"
#include "error.h"

static int dispatch_1(int code_error)
{
    if (code_error == OP_FILE_ERR)
        return my_putstr(2, OP_FILE_MSG);
    if (code_error == READ_FILE_ERR)
        return my_putstr(2, READ_FILE_MSG);
    if (code_error == FLAG_ERR)
        return my_putstr(2, FLAG_MSG);
    return KO;
}

int dispatch(int code_error)
{
    if (!PUT_ERROR)
        return OK;
    if (code_error == ERROR_ERR)
        return my_putstr(2, ERROR_MSG);
    if (code_error == UNDEF_ERR)
        return my_putstr(2, UNDEF_MSG);
    if (code_error == OVERFLOW)
        return my_putstr(2, OVERFLOW_MSG);
    if (code_error == PTR_ERR)
        return my_putstr(2, PTR_MSG);
    if (code_error == MALLOC_ERR)
        return my_putstr(2, MALLOC_MSG);
    if (code_error == WRITE_ERR)
        return my_putstr(2, WRITE_MSG);
    if (code_error == ARGC_ERR)
        return my_putstr(2, ARGC_MSG);
    if (code_error == ARGV_ERR)
        return my_putstr(2, ARGV_MSG);
    return dispatch_1(code_error);
}
