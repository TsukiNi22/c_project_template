/*
** EPITECH PROJECT, 2024
** test_redirect.c
** File description:
** To redirect output
*/

#include "debug.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
