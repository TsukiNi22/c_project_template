/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** Return a number from a string
*/

#include "include.h"
#include "math.h"

static int size_int(char const *str, int const n)
{
    int c = 0;

    if (!str)
        return 0;
    for (int i = 1; c; i++) {
        if (i > 10)
            return 1;
        c = ((int) str[i + n - 1] > 47 && (int) str[i + n - 1] <= 58);
    }
    return 0;
}

static int get_signe(char const *str, int const n)
{
    int signe = 1;

    if (!str)
        return 0;
    for (int i = 0; i <= n; i++)
        signe *= 1 - 2 * (str[i] == '-');
    return (signe > 0);
}

static int int_less(char const *str, int const n)
{
    char *max = "2147483647";
    int c;
    int cb;
    int size = 0;
    int signe = get_signe(str, n);

    if (!str)
        return 0;
    for (; (int) str[size + n] > 47 && (int) str[size + n] < 58; size++);
    if (size != 10)
        return 0;
    for (int i = 0; (int) str[i + n] > 47 && (int) str[i + n] < 58; i++) {
        cb = (str[i + n] == '8' && i == 9 && !signe);
        if (!(str[i + n] <= max[i] || cb))
            return 1;
    }
    return 0;
}

static int condition_2(int *cb, int *c, int *exist, int condition)
{
    if (!cb || !c || !exist)
        return 0;
    if (*cb) {
        *c += condition;
        *exist = 1;
    } else if (!*cb && *exist)
        return 1;
    return 0;
}

static int verif_size_int(char const *str)
{
    int exist = 0;
    int c = 0;
    int cb;
    int c_send;

    if (!str)
        return 0;
    for (int i = 0; str[i]; i++) {
        cb = ((int) str[i] > 47 && (int) str[i] < 58);
        c_send = (size_int(str, i) || int_less(str, i));
        if (condition_2(&cb, &c, &exist, c_send))
            break;
        if (c > 0)
            return 1;
    }
    if (!exist)
        return 1;
    return 0;
}

static int condition_1(int *c, int *size, int *already)
{
    if (!c || !size || !already)
        return 0;
    if (*c) {
        *size += 1;
        *already = 1;
    } else if (!*c && *already)
        return 1;
    return 0;
}

static int get_first_number(char const *str)
{
    int my_int = 0;
    int already = 0;
    int size = 0;
    int c = 0;
    int n;

    if (!str)
        return 0;
    for (int i = 0; str[i]; i++) {
        c = ((int) str[i] > 47 && (int) str[i] < 58);
        if (c && !already)
            n = i;
        if (condition_1(&c, &size, &already))
            break;
    }
    for (int i = n; i < n + size; i++)
        my_int += (((int) str[i]) - 48) * my_pow(10, size - (i - n) - 1);
    my_int *= 1 - 2 * (!get_signe(str, n));
    return my_int;
}

int my_getnbr(char const *str)
{
    int my_int = 0;

    if (!str || verif_size_int(str))
        return 0;
    my_int = get_first_number(str);
    return my_int;
}
