/*
** EPITECH PROJECT, 2024
** error.h
** File description:
** Header for the error handling / error code
*/

#pragma once

#ifndef ERROR_H
    #define ERROR_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* error_return_write */
    #define PUT_ERROR 0
    #define CUSTOM_PUT_ERROR 1

    /* error_return */
    #define OK 0
    #define KO -1
    #define ERROR 84
    #define ERR 84

    /* error_code */
    #define ERROR_ERR -2
    #define UNDEF_ERR -1
    #define OVERFLOW 0
    #define PTR_ERR 1
    #define MALLOC_ERR 2
    #define WRITE_ERR 3
    #define ARGC_NBR_ERR 4
    #define ARGV_ERR 5
    #define OP_FILE_ERR 6

    /* error_sentence */
    #define ERROR_MSG "Error: An Error have ocured in the error return"
    #define UNDEF_MSG "Error: Undefinied Error"
    #define OVERFLOW_MSG "Error: Overflow on a variable"
    #define PTR_MSG "Error: The given pointer is NULL"
    #define MALLOC_MSG "Error: The allocation attempt with malloc have fail"
    #define WRITE_MSG "Error: The write function have failed"
    #define ARGC_NBR_MSG "Error: Incorrect number of argument given to main"
    #define ARGV_MSG "Error: Incorrect input in the given argument"
    #define OP_FILE_MSG "Error: 'Invalid Permision' or 'No Existant File'"

//----------------------------------------------------------------//
/* PROTOTYPE */

/* error_handling */
void err_dispatch_v(int error_number, char *error_info);
void *err_dispatch_n(int error_number, char *error_info);
int err_dispatch(int error_number, char *error_info, int to_return);
int err_custom(char *error_info, int to_return);

/*
** Error -2: Can't return Error
** Error -1: Undefinied Error
** Error 0: Overflow
** Error 1: The given pointer, return NULL
** Error 2: Allocation of pointer, return NULL
** Error 3: Write error
** Error 4: Not enought argv
** Error 5: Wrong input in given argument
** Error 6: Can't open file
*/

#endif /* ERROR_H */
