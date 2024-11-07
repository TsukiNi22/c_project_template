/*
** EPITECH PROJECT, 2024
** test_my_printf_normal.c
** File description:
** Test on normal string without %
*/

#include "printf.h"
#include "define.h"
#include "debug.h"

Test(my_printf, test01_normal_string, .init = redirect)
{
    my_print("Hello World!\n");
    cr_assert_stdout_eq_str("Hello World!\n");
}