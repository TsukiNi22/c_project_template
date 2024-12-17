/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** Transform a str in a world array
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static char *my_strdup_local(char const **src, char const *base_str,
    int size, int i)
{
    char *str = NULL;
    int len = 0;

    if (!src || !(*src) || !base_str)
        return err_prog_n(PTR_ERR, "In: my_strdup");
    len = my_strlen(*src);
    if (len < 0)
        return err_prog_n(UNDEF_ERR, "In: my_strdup 1");
    if (my_malloc_c(&str, len + 1) == KO)
        return err_prog_n(MALLOC_ERR, "In: my_strdup");
    if (!my_strncpy(str, *src, size))
        return err_prog_n(UNDEF_ERR, "In: my_strdup 2");
    *src = base_str + i + 1;
    return str;
}

static int alloc_array(char const *str, char const *identifier,
    char ***str_array)
{
    int count = 1;
    int res = 0;

    if (!str || !identifier)
        return err_prog(PTR_ERR, "In: my_str_to_str_array > get_size", KO);
    for (int i = 0; str[i]; i++) {
        res = my_strfind(identifier, str[i]);
        if (res == KO)
            count++;
        if (res == -2)
            return err_prog(UNDEF_ERR, "In: str_to_str_array > gt_size 1", KO);
    }
    *str_array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count + 1; i++)
        (*str_array)[i] = NULL;
    if (!(*str_array))
        return err_prog(MALLOC_ERR, "In: str_to_str_array > get_size 2", KO);
    str_array[count] = NULL;
    return OK;
}

char **my_str_to_str_array(char const *str, char const *identifier, bool take)
{
    char **str_array = NULL;
    char const *start_ptr = str;
    int count = -1 * !take;
    int index = 0;

    if (!str || !identifier || alloc_array(str, identifier, &str_array) == KO)
        return err_prog_n(PTR_ERR, "In: my_str_to_str_array");
    for (int i = 0; str[i]; i++) {
        count++;
        if (my_strfind(identifier, str[i]) != KO ||
            (!str[i + 1] && my_strfind(identifier, str[i - 1]) == KO)) {
            count += (!str[i + 1] && my_strfind(identifier, str[i - 1]));
            str_array[index] = my_strdup_local(&start_ptr, str, count, i);
            count = -1 * !take;
            index++;
        }
        if (index > 0 && !str_array[index - 1])
            return err_prog_n(UNDEF_ERR, "In: str_to_str_array 2");
    }
    return str_array;
}
