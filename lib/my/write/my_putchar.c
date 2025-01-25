/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** Write a given char
*/

#include "error.h"
#include <unistd.h>

int my_putchar(char c)
{
    if (write(1, &c, 1) != 1)
        return err_prog(WRITE_ERR, "In: my_putchar", KO);
    return OK;
}
