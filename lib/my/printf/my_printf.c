/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** Main function of my_printf
** That call the other function when the identifier '%' is found
*/

#include "char.h"
#include "memory.h"
#include "math.h"
#include "write.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int data_clean(printf_data_t *data)
{
    if (!data)
        return err_dispatch(PTR_ERR, "In: printf 3.1", KO);
    va_end(data->ap);
    free(data);
    return 0;
}

static int star_replacement(printf_data_t *data, int *i, int *res)
{
    if (*res >= 0)
        return 0;
    if (!data || !(data->str) || !i || !res)
        return err_dispatch(PTR_ERR, "In: printf 2.1", KO);
    for (; data->str[*i] && data->str[*i] != '*'; (*i)++)
        my_putchar(data->str[*i]);
    my_putnbr(va_arg(data->ap, int));
    (*i)++;
    *res = 0;
    return 0;
}

static int write_char(char c, int *identifier_check, int i)
{
    if (c != IDENTIFIER || identifier_check[i]) {
        my_putchar(c);
        return 0;
    }
    return -1;
}

static int identifier_find(printf_data_t *data, int *identifier_check, int *i)
{
    identifier_check[*i] = 1;
    (*i)++;
    return identifier_encouter(data, i);
}

int my_printf(char *str, ...)
{
    printf_data_t *data = malloc(sizeof(printf_data_t));
    int identifier_check[my_strlen(str)];
    int res;

    my_calloc_int(identifier_check, my_strlen(str));
    if (!str)
        return err_dispatch(PTR_ERR, "In: printf 1", KO);
    if (!data)
        return err_dispatch(MALLOC_ERR, "In: printf", KO);
    va_start(data->ap, str);
    data->str = str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == IDENTIFIER)
            res = identifier_find(data, identifier_check, &i);
        if (res == KO)
            return err_dispatch(UNDEF_ERR, "In: printf", KO);
        star_replacement(data, &i, &res);
        i += write_char(str[i], identifier_check, i);
    }
    return data_clean(data);
}
