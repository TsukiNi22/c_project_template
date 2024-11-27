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
    int len;

    ERR_DN(PTR_ERR, "In: my_strdup", (!src || !(*src) || !base_str));
    len = my_strlen(*src);
    ERR_DN(UNDEF_ERR, "In: my_strdup 1", (len < 0));
    ERR_DN(MALLOC_ERR, "In: my_strdup",
    (my_malloc_c(&str, len + 1) == KO));
    ERR_DN(UNDEF_ERR, "In: my_strdup 2", (!my_strncpy(str, *src, size)));
    *src = base_str + i + 1;
    return str;
}

static int alloc_array(char const *str, char const *identifier,
    char ***str_array)
{
    int count = 1;
    int res;

    ERR_D(PTR_ERR, "In: my_str_to_str_array > get_size", KO,
    (!str || !identifier));
    for (int i = 0; str[i]; i++) {
        res = my_strfind(identifier, str[i]);
        if (res == KO)
            count++;
        ERR_D(UNDEF_ERR, "In: str_to_str_array > get_size 1", KO, (res == -2));
    }
    *str_array = malloc(sizeof(char *) * (count + 1));
    ERR_D(MALLOC_ERR, "In: str_to_str_array > get_size 2", KO, (!str_array));
    str_array[count] = NULL;
    return OK;
}

char **my_str_to_str_array(char const *str, char const *identifier, bool take)
{
    char **str_array = NULL;
    char const *start_ptr = str;
    int index = 0;
    int count = 0;
    int i;

    ERR_DN(PTR_ERR, "In: my_str_to_str_array", (!str || !identifier));
    ERR_DN(UNDEF_ERR, "In: my_str_to_str_array 1",
    (alloc_array(str, identifier, &str_array) == KO));
    for (i = 0; str[i]; i++) {
        count++;
        if (my_strfind(identifier, str[i]) != KO ||
            (!str[i + 1] && my_strfind(identifier, str[i - 1]) == KO)) {
            str_array[index] = my_strdup_local(&start_ptr, str, count, i);
            ERR_DN(UNDEF_ERR, "In: str_to_str_array 2", (!str_array[index]));
            count = !take * -1;
            index++;
        }
    }
    return str_array;
}
