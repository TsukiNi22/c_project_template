/*
** EPITECH PROJECT, 2024
** my_ftoa.c
** File description:
** Return the string from a float
*/

#include "math.h"
#include "char.h"
#include "write.h"
#include "memory.h"
#include "printf.h"
#include "include.h"
#include "error.h"

static int my_strlen_local(char *str)
{
    int len = 0;

    if (!str)
        return err_dispatch(PTR_ERR, "In: strlen dtoa", -1);
    for (; str[len] != '\0'; len++);
    free(str);
    return len;
}

static char *my_strcat_local(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    if (!dest || !src || len < 0)
        err_dispatch_n(PTR_ERR, "In: strcat dtoa");
    for (; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    free(src);
    return dest;
}

static int get_d_integer(long double nbr, long double *nbr_already,
    int *depth, char **str)
{
    long long cast;
    int return_val;
    int signe;

    nbr -= *nbr_already;
    signe = (nbr < 0);
    return_val = (nbr < LLONG_MAX);
    nbr *= 1 - 2 * (signe == 1 && *depth != 0);
    for (; nbr > LLONG_MAX; nbr /= 10)
        *nbr_already *= 10;
    cast = (long long) nbr;
    *str = my_realloc_str(*str, my_strlen_local(my_itoa(cast)));
    my_strcat_local(*str, my_itoa(cast));
    *nbr_already += cast * (1 - 2 * (signe == 1));
    (*depth)++;
    return return_val;
}

static int get_d_decimal(long double nbr, long double *nbr_already,
    int *depth, char **str)
{
    long long ll_cast = 0;
    long double d_cast = 0;
    int return_val;
    int signe = (nbr < 0);
    char *tmp;

    nbr = (nbr - *nbr_already * (1 - 2 * signe)) * (1 - 2 * signe);
    if ((long long) (nbr * my_pow(10, my_log(LLONG_MAX, 10) - 1)) == 0)
        return 1;
    for (int i = 0; nbr * 10 < LLONG_MAX && i < my_log(LLONG_MAX, 10) * 2; i++)
        nbr *= 10;
    ll_cast = (long long) nbr;
    d_cast = (long double) ll_cast;
    *str = my_realloc_str(*str, my_strlen_local(my_itoa(ll_cast)));
    my_strcat_local(*str, my_itoa(ll_cast));
    for (; d_cast > 1; d_cast /= 10);
    *nbr_already += d_cast * (1 - 2 * (signe == 1));
    return_val = (ll_cast == 0 || *depth >= 10);
    (*depth)++;
    return return_val;
}

static int clear_char(char *str)
{
    if (!str)
        return err_dispatch(PTR_ERR, "In: dtoa", KO);
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '.')
            str[i] = '0';
    }
    return 0;
}

static int set_dot(char *str)
{
    int len = my_strlen(str);

    str[len] = '.';
    str[len + 1] = '\0';
    return 0;
}

char *my_ftoa(long double nbr)
{
    char *str = malloc(sizeof(char) * 1);
    long double nbr_already = 0;
    int depth = 0;
    int size;

    my_calloc_str(str, 2);
    while (get_d_integer(nbr, &nbr_already, &depth, &str) == 0);
    set_dot(str);
    if (depth < 3) {
        for (depth = 0; get_d_decimal(nbr, &nbr_already, &depth, &str) == 0;);
    }
    if (depth >= 3) {
        size = my_strlen(str);
        str = my_realloc_str(str, 6);
        for (int i = 0; i < 6; i++)
            str[size + i] = '0';
        str[size + 6] = '\0';
    }
    clear_char(str);
    return str;
}