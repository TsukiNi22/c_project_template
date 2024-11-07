/*
** EPITECH PROJECT, 2024
** my_printf_extract_info.c
** File description:
** Extract the info from the given string
*/


#include "char.h"
#include "memory.h"
#include "include.h"
#include "printf.h"

int get_precision(va_list ap, char *precision, int basic_return)
{
    char *nbr;
    int n;

    if (my_strcmp(precision, "") == 0)
        return basic_return;
    if (my_strcmp(precision, ".") == 0)
        return 0;
    if (my_strcmp(precision, ".*") == 0)
        return va_arg(ap, int);
    n = my_strlen(precision);
    nbr = malloc(sizeof(char) * (n - 1));
    my_calloc_str(nbr, n);
    for (int i = 1; precision[i]; i++)
        nbr[i - 1] = precision[i];
    n = my_atoi(nbr);
    free(nbr);
    return n;
}

int get_field(va_list ap, char *flag, char *field, int basic_return)
{
    char *nbr;
    char c = flag[my_strlen(flag) - 1];
    int n;

    if (c != '*' && my_strcmp(field, "") == 0)
        return basic_return;
    if (my_strcmp(field, "") == 0)
        return 0;
    if (c == '*')
        return va_arg(ap, int);
    n = my_strlen(field) + 1;
    nbr = malloc(sizeof(char) * n);
    my_calloc_str(nbr, n);
    for (int i = 0; field[i]; i++)
        nbr[i] = field[i];
    n = my_atoi(nbr);
    free(nbr);
    return n;
}

int flag_in(char *flag, char flag_to_verif)
{
    for (int i = 0; flag[i]; i++) {
        if (flag[i] == flag_to_verif)
            return 1;
    }
    return 0;
}
