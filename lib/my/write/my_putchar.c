/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** Write a given char
*/

#include "include.h"
#include "error.h"

int my_putchar(char c)
{
    ERR_D(WRITE_ERR, "In: my_putchar", KO, (write(1, &c, 1) != 1));
    return OK;
}
