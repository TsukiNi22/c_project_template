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

    /* math */
    #define ABS(value) ((value) * (1 - 2 * (value < 0 || value == -0)))

#endif
