/*
** EPITECH PROJECT, 2025
** write.h
** File description:
** Header for all function who print something
*/

#ifndef WRITE_H
    #define WRITE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "linked.h" // linked_list_t
    #include "matrice.h" // matrice_t

//----------------------------------------------------------------//
/* PROTOTYPE */

/* string */
int my_putchar(char c); // Error: KO
int my_putstr(int output, char const *str); // Error: KO
int my_show_word_array(char const **tab); // Error: KO

/* math */
int my_putnbr(long long nb); // Error: KO
int my_putnbr_base(unsigned long long nbr, char const *base); // Error: KO
int display_matrice(matrice_t *matrice); // Error: KO

/* other */
int display_linked(linked_list_t *linked_list); // Error: KO

#endif /* WRITE_H */
