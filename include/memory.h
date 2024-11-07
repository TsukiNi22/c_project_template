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

/* memory_alloc */
int my_calloc_str(char *str, int size); // Error: KO
int my_calloc_int(int *array, int size); // Error: KO
int my_calloc_float(float *array, int size); // Error: KO

/* memory_realloc */
char *my_strdup(char const *src); // Error: NULL
char *my_realloc_str(char *str, int add); // Error: NULL

#endif /* MEMORY */
