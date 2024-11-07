/*
** EPITECH PROJECT, 2024
** csfml.h
** File description:
** Header for all thing who have a link with csfml
*/

#ifndef CSFML
    #define CSFML

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* global */
    #include "include.h" // Include csfml type

//----------------------------------------------------------------//
/* TYPEDEF */

/* frame */
typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

#endif /* CSFML */
