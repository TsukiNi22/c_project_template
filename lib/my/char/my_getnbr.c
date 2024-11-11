/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** Return a number from a string
*/

#include "math.h"
#include "memory.h"
#include "include.h"
#include "error.h"

static bool size_int(char const *str, int const n)
{
    int c = 0;

    ERR_D(PTR_ERR, "In: my_getnbr > size_int", false, (!str));
    for (int i = 1; c; i++) {
        if (i > 10)
            return true;
        c = ((int) str[i + n - 1] > 47 && (int) str[i + n - 1] <= 58);
    }
    return false;
}

static int get_signe(char const *str, int const n)
{
    int signe = 1;

    ERR_D(PTR_ERR, "In: my_getnbr > get_signe", 0, (!str));
    for (int i = 0; i <= n; i++)
        signe *= 1 - 2 * (str[i] == '-');
    return (signe > 0);
}

static bool int_less(char const *str, int const n)
{
    char *max = "2147483647";
    int c;
    int cb;
    int size = 0;
    int signe = get_signe(str, n);

    ERR_D(PTR_ERR, "In: my_getnbr > int_less", false, (!str));
    for (; (int) str[size + n] > 47 && (int) str[size + n] < 58; size++);
    if (size != 10)
        return false;
    for (int i = 0; (int) str[i + n] > 47 && (int) str[i + n] < 58; i++) {
        cb = (str[i + n] == '8' && i == 9 && !signe);
        if (!(str[i + n] <= max[i] || cb))
            return true;
    }
    return false;
}

static bool condition_2(int *cb, int *c, bool *exist, int condition)
{
    ERR_D(PTR_ERR, "In: my_getnbr > cd_2", false, (!cb || !c || !exist));
    if (*cb) {
        *c += condition;
        *exist = true;
    } else if (!*cb && *exist)
        return true;
    return false;
}

static bool verif_size_int(char const *str)
{
    bool exist = false;
    int c = 0;
    int cb;
    int c_send;

    ERR_D(PTR_ERR, "In: my_getnbr > verif_size_int", false, (!str));
    for (int i = 0; str[i]; i++) {
        cb = ((int) str[i] > 47 && (int) str[i] < 58);
        c_send = (size_int(str, i) || int_less(str, i));
        if (condition_2(&cb, &c, &exist, c_send))
            break;
        if (c > 0)
            return true;
    }
    if (!exist)
        return true;
    return false;
}

static bool condition_1(int *c, int *size, bool *already)
{
    ERR_D(PTR_ERR, "In: my_getnbr > cd_1", false, (!c || !size || !already));
    if (*c) {
        *size += 1;
        *already = true;
    } else if (!*c && *already)
        return true;
    return false;
}

static int get_first_number(char const *str)
{
    bool already = false;
    int my_int = 0;
    int size = 1;
    int c = 0;
    int n;

    ERR_D(PTR_ERR, "In: my_getnbr > get_first_number", 0, (!str));
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

    ERR_D(PTR_ERR, "In: my_getnbr", 0, (!str || verif_size_int(str)));
    my_int = get_first_number(str);
    return my_int;
}
