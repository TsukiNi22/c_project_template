/*
** EPITECH PROJECT, 2024
** my_atof.c
** File description:
** Return the float of a string
*/

#include "math.h"
#include "char.h"
#include "include.h"
#include "error.h"

static long double my_atof_basic(const char *str)
{
    long double my_double = 0;
    long double mult;
    int size;
    bool diff = false;

    ERR_D(PTR_ERR, "In: my_atof > my_atof_basic", 0, (!str));
    size = my_strlen(str) - 1;
    ERR_D(UNDEF_ERR, "In: my_atof > my_atof_basic", 0, (size < 0));
    for (int i = 0; str[i]; i++) {
        if (str[size - i] == '-' && size - i == 0)
            diff = true;
        else {
            mult = my_pow(10, i - diff);
            my_double += (((long double) str[size - i]) - 48) * mult;
        }
    }
    if (str[0] && str[0] == '-' && my_double > 0)
        my_double *= -1;
    return my_double;
}

static int my_atof_second(const char *str, long double *my_float)
{
    int size = my_strlen(str) - 1;
    int cut_place = my_strfind(str, '.');
    char *first_array = my_cut_str(str, 1, cut_place);
    char *second_array = my_cut_str(str, 0, cut_place);
    int second_size = my_strlen(second_array);
    long double mult = my_pow(10, second_size * -1);
    long double first_int = my_atof_basic(first_array);
    long double second_int = my_atof_basic(second_array);

    ERR_D(UNDEF_ERR, "In: my_atof > my_atof_second", KO,
    (!str || !my_float || !first_array || !second_array ||
    size < 0 || cut_place == KO * -1 || second_size < 0));
    if (first_int < 0)
        *my_float = first_int + second_int * mult * -1;
    else
        *my_float = first_int + second_int * mult;
    return OK;
}

long double my_atof(const char *str)
{
    long double my_float;

    ERR_D(PTR_ERR, "In: my_atof", 0,
    (!str || my_atof_second(str, &my_float) == KO));
    return my_float;
}
