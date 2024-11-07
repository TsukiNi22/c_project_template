/*
** EPITECH PROJECT, 2024
** debug.h
** File description:
** Header with include useful for debugin
*/

#ifndef DEBUG
    #define DEBUG

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* debug */
    #include <stdio.h> // printf
    #include <criterion/criterion.h> // unit test
    #include <criterion/redirect.h> // unit test -> stderr / stdout

void redirect(void);

#endif /* DEBUG */
