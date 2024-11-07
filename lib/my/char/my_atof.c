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
    int array_size = my_strlen(str) - 1;
    int diff = 0;
    long double my_double = 0;
    long double mult;

    if (!str || array_size < 0)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (str[array_size - i] == '-' && array_size - i == 0)
            diff = 1;
        else {
            mult = my_pow(10, i - diff);
            my_double += (((long double) str[array_size - i]) - 48) * mult;
        }
    }
    if (str[0] && str[0] == '-' && my_double > 0)
        my_double *= -1;
    return my_double;
}

static int my_atof_second(const char *str, long double *my_float)
{
    int array_size = my_strlen(str) - 1;
    int cut_place = my_strfind(str, '.');
    char *first_array = my_cut_str(str, 1, cut_place);
    char *second_array = my_cut_str(str, 0, cut_place);
    int second_array_size = my_strlen(second_array);
    long double mult = my_pow(10, second_array_size * -1);
    long double first_int = my_atof_basic(first_array);
    long double second_int = my_atof_basic(second_array);

    if (!str || !my_float || !first_array || !second_array)
        return err_dispatch(PTR_ERR, "In: atof 2.1", KO);
    if (array_size < 0 || cut_place == KO * -1 || second_array_size < 0)
        return err_dispatch(UNDEF_ERR, "In: atof", KO);
    if (first_int < 0)
        *my_float = first_int + second_int * mult * -1;
    else
        *my_float = first_int + second_int * mult;
    return 0;
}

long double my_atof(const char *str)
{
    long double my_float;

    if (!str || my_atof_second(str, &my_float) == KO)
        return err_dispatch(PTR_ERR, "In: atof 1", 0);
    return my_float;
}
