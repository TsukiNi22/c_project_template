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
    /* INCLUDE */

    /* type */
    #include "sample.h" // main_data_t
    #include <stdbool.h> // boolean

    /* macro */
    #include "error.h" // Error macro

    //----------------------------------------------------------------//
    /* MACRO */

    /* __attribute__ */
    #define USED __attribute__((used))
    #define UNUSED __attribute__((unused))
    #define AUTOFREE __attribute__((cleanup(free)))
    #define AUTOCLOSE __attribute__((cleanup(close)))

    /* flag_handle */
    #define INFO(c, v, b) if (c > 1) res = print_info(c, v, b)
    #define INFO_FLAG(c, v, b) if (c > 1) res = print_info_flag(c, v, b)
    #define INIT_FLAG(c, v, d) ERR_C("Flag", KO, (init_flag(c, v, d) == KO))

    /* usefull */
    #define EXIT(condition, literal) if (condition) return literal

    /* math */
    #define ABS(x) x = ((x) * (1 - 2 * (x < 0 || x == -0)))

//----------------------------------------------------------------//
/* PROTOTYPE */

/* flag */ // Error: KO
int print_info(int argc, char const *argv[], bool *out);
int print_info_flag(int argc, char const *argv[], bool *out);
int init_flag(int argc, char const *argv[], main_data_t *data);
int flag_init_null(int argc, char const *argv[], main_data_t *data);

#endif
