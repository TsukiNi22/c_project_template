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
    if (write(1, &c, 1) != 1)
        return err_dispatch(WRITE_ERR, "In: putchar", KO);
    return 0;
}
