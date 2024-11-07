/*
** EPITECH PROJECT, 2024
** math.h
** File description:
** Header for all thing who have a link with math
*/

#pragma once

#ifndef MATH
    #define MATH

    //----------------------------------------------------------------//
    /* DEFINE */

    /* math */
    #define PI 3.1415926535
    #define EULER 2.7182818284
    #define H_ZERO (my_pow(10, -7))
    #define ACCURATE 1000

//----------------------------------------------------------------//
/* PROTOTYPE */

/* math_gestion */
int my_swap(int *a, int *b); // Error: KO
int my_sort_int_array(int *tab, int size); // Error: KO
int my_find_prime_sup(int nb); // Error: No
char *my_convertnbr_base(unsigned long long nbr, char const *base); // NULL

/* math_comparaison */
int my_isneg(int nb); // Error: KO
int my_is_prime(int nb); // Error: KO

/* math_operator */
float my_sqrt(float x); // Error: no
long double my_pow(double n, double power); // Serie de Taylor generaliser
double my_gamma(float x); // Error: 0
double my_factorial(int x); // Error: KO
int my_binomial(float n, float k); // Error: -1

/* math_function */
long double my_log(double base, double x); // Error: inf (div by 0)

/* math_trigonometrie */
float my_sin(float x); // Error: KO
float my_cos(float x); // Error: KO
double my_tan(float x); // Error: 0
float rad_degree(float x); // Error: No
float degree_rad(float x); // Error: No

#endif /* MATH */
