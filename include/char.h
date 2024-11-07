/*
** EPITECH PROJECT, 2024
** char.h
** File description:
** Header for all thing who have a link with str
*/

#pragma once

#ifndef CHAR
    #define CHAR

//----------------------------------------------------------------//
/* PROTOTYPE */

/* char_gestion */
char *my_strcpy(char *dest, char const *src); // Error: NULL
char *my_strncpy(char *dest, char const *src, int n); // Error: NULL
char *my_revstr(char *str); // Error: NULL
char *my_strupcase(char *str); // Error: NULL
char *my_strlowcase(char *str); // Error: NULL
char *my_strcapitalize(char *str); // Error: NULL
char *my_strcat(char *dest, char const *src); // Error: NULL
char *my_strncat(char *dest, char const *src, int nb); // Error: NULL
char *concat_params(int ac, char **av); // Error: NULL
char **my_str_to_word_array(char const *str); // Error: NULL
char *my_cut_str(const char *char_array, int before, int cut_place); // NULL

/* char_information  */
int my_strlen(char const *str); // Error: -1
char *my_strstr(char *str, char const *to_find); // Error: NULL
float count_occurence(char const *str, char const c); // Error: -1
int my_strfind(const char *char_array, const char find_char); // Error: -1
int my_get_index(char const *str, char const c); // Error: -1

/* char_comparaison */
int my_strcmp(char const *s1, char const *s2); // Error: KO
int my_strncmp(char const *s1, char const *s2, int n); // Error: KO
int my_str_isalpha(char const *str); // Error: KO
int my_str_isnum(char const *str); // Error: KO
int my_str_islower(char const *str); // Error: KO
int my_str_isupper(char const *str); // Error: KO
int my_str_isprintable(char const *str); // Error: KO
int my_char_islower(char const c); // Error: KO
int my_char_isupper(char const c); // Error: KO

/* int_float_to_str */
char *my_itoa(long long n); // Error: NULL
char *my_ftoa(long double n); // Error: NULL

/* str_to_int_float */
int my_getnbr(char const *str); // Error: 0
long long my_atoi(const char *char_array); // Error: 0
long double my_atof(const char *char_array); // Error: 0

#endif /* CHAR */
