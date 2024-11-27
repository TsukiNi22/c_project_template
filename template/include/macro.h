/*
** EPITECH PROJECT, 2024
** my_macro_abs.h
** File description:
** Header for all macro
*/

#pragma once

#ifndef MACRO
    #define MACRO

    //----------------------------------------------------------------//
    /* MACRO */

    /* __attribute__ */
    #define USED __attribute__((used))
    #define UNUSED __attribute__((unused))
    #define AUTOFREE __attribute__((cleanup(free)))
    #define AUTOCLOSE __attribute__((cleanup(close)))

    /* usefull */
    #define INFO(c, v) if (c > 1 && v) return print_info(c, v)
    #define INFO_FLAG(c, v) if (c > 2 && v) return print_info_flag(c, v)

    /* math */
    #define ABS(value) ((value) * (1 - 2 * (value < 0 || value == -0)))

//----------------------------------------------------------------//
/* PROTOTYPE */

/* usefull */
int print_info(int argc, char const *argv[]); // Error: EPITECH_ERR
int print_info_flag(int argc, char const *argv[]); // Error: EPITECH_ERR

#endif
