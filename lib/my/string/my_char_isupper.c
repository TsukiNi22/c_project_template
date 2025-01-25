/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** Verif if the given char is only upper case
*/

#include <stdbool.h>

bool my_char_isupper(char const c)
{
    return (c >= 'A' && c <= 'Z');
}
