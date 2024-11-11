/*
** EPITECH PROJECT, 2024
** math.h
** File description:
** Header for all thing who have a link with memory
*/

#pragma once

#ifndef MEMORY
    #define MEMORY

//----------------------------------------------------------------//
/* PROTOTYPE */

/* memory_calloc */
int my_calloc(void *ptr, int size, int type_size); // Error: KO
void *my_malloc(int size, int type_size); // Error: NULL
void *my_realloc(void *ptr, int add, int size, int type_size); // Error: NULL

/* memory_char */
char *my_strdup(char const *src); // Error: NULL

#endif /* MEMORY */
