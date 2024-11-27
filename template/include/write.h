/*
** EPITECH PROJECT, 2024
** write.h
** File description:
** Header for all function who print something
*/

#pragma once

#ifndef WRITE
    #define WRITE

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "linked.h" // linked_list_t

//----------------------------------------------------------------//
/* PROTOTYPE */

/* write */
int my_putchar(char c); // Error: KO
int my_putnbr(long long nb); // Error: KO
int my_putstr(int output, char const *str); // Error: KO
int my_show_word_array(char const **tab); // Error: KO
int my_putnbr_base(unsigned long long nbr, char const *base); // Error: KO
int display_linked(linked_list_t *linked_list); // Error: KO

#endif /* WRITE */
