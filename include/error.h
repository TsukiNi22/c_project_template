/*
** EPITECH PROJECT, 2025
** error.h
** File description:
** Header for the error handling / error code
*/

#ifndef ERROR_H
    #define ERROR_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* error_return_write */
    #define PUT_ERROR 1
    #define CUSTOM_PUT_ERROR 1
    #define SYSTEM_PUT_ERROR 1

    /* error_return */
    #ifndef KO
        #define KO -1
    #endif /* KO */
    #ifndef OK
        #define OK 0
    #endif /* OK */
    #ifndef FATAL_ERR
        #define FATAL_ERR 255
    #endif /* FATAL_ERR */
    #ifndef ERROR
        #define ERROR 84
    #endif /* ERROR */
    #ifndef ERR
        #define ERR 84
    #endif /* ERR */
    #define EPITECH_ERR 84

    /* error_code */
    #define ERROR_ERR -2
    #define UNDEF_ERR -1
    #define OVERFLOW 0
    #define PTR_ERR 1
    #define MALLOC_ERR 2
    #define WRITE_ERR 3
    #define ARGC_ERR 4
    #define ARGV_ERR 5
    #define OP_FILE_ERR 6
    #define READ_FILE_ERR 7
    #define FLAG_ERR 8

    /* error_sentence */
    #define ERROR_MSG "Error: An Error have ocured in the error return"
    #define UNDEF_MSG "Error: Undefinied Error"
    #define OVERFLOW_MSG "Error: Overflow on a variable"
    #define PTR_MSG "Error: The given pointer is NULL"
    #define MALLOC_MSG "Error: The allocation attempt with malloc have fail"
    #define WRITE_MSG "Error: The write function have failed"
    #define ARGC_MSG "Error: Incorrect number of argument given to main"
    #define ARGV_MSG "Error: Incorrect input in the given argument"
    #define OP_FILE_MSG "Error: 'Invalid Permision' or 'No Existant File'"
    #define READ_FILE_MSG "Error: 'Can't' or 'Fail' to read the file"
    #define FLAG_MSG "Error: Unknow flag given for execution"

    //----------------------------------------------------------------//
    /* MACRO */

    /* err_macro */
    #define ERR_D(er, msg, ret, c) if (c) return err_prog(er, msg, ret)
    #define ERR_DN(err, msg, c) if (c) return err_prog_n(err, msg)
    #define ERR_DV(err, msg, c) if (c) return err_prog_v(err, msg)
    #define ERR_C(msg, ret, c) if (c) return err_custom(msg, ret)
    #define ERR_CN(msg, c) if (c) return err_custom_n(msg)
    #define ERR_CV(msg, c) if (c) return err_custom_v(msg)
    #define ERR_S(msg, c) if (c) return err_system(msg)

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stdbool.h>

//----------------------------------------------------------------//
/* PROTOTYPE */

/* error_handling */
void err_prog_v(int error_number, char *error_info); // Error: None
void *err_prog_n(int error_number, char *error_info); // Error: None
int err_prog(int error_number, char *error_info, int to_return); // Error: None
void err_custom_v(char *error_info); // Error: None
void *err_custom_n(char *error_info); // Error: None
int err_custom(char *error_info, int to_return); // Error: None
void err_system_v(char *error_info); // Error: None
void *err_system_n(char *error_info); // Error: None
int err_system(char *error_info, int to_return); // Error: None

/* print_error_ouput */
void error_error(void); // Error: None
void print_error(int error_number); // Error: None
void print_error_info(char *error_info, bool custom); // Error: None
int dispatch(int code_error); // Error: KO

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
** Error 7: Can't read file
** Error 8: Flag is unknow
*/

#endif /* ERROR_H */
