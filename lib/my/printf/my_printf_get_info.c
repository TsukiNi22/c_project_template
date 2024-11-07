/*
** EPITECH PROJECT, 2024
** my_printf_get_info.c
** File description:
** Function to get the flag, field, ...
** and other usefule information between the identifier and the specifier
*/

#include "char.h"
#include "memory.h"
#include "printf.h"
#include "include.h"
#include "define.h"
#include "error.h"

char *get_info_single_char(char *str, char *valid_char_list, int *i, int stop)
{
    char *info;
    int size = my_strlen(str);

    if (size < 0 || !str || !valid_char_list)
        return err_dispatch_n(PTR_ERR, "In: pritnf_info");
    info = malloc(sizeof(char) * size);
    my_calloc_str(info, size);
    for (int j = 0; my_strfind(valid_char_list, str[*i]) != -1; j++) {
        info[j] = str[*i];
        (*i)++;
        if (stop)
            return info;
    }
    return info;
}

char *get_info_mult_char(char *str, char *valid_char_list, int *i, int stop)
{
    char *info;
    char tmp[3];
    int size = my_strlen(str);

    info = malloc(sizeof(char) * size);
    my_calloc_str(info, size);
    my_calloc_str(tmp, 3);
    tmp[0] = str[*i];
    if (str[*i + 1] && my_strfind(valid_char_list, str[*i + 1]) != -1)
        tmp[1] = str[*i + 1];
    if (my_strstr(valid_char_list, tmp) != NULL) {
        for (int j = 0; tmp[j]; j++)
            info[j] = tmp[j];
        *i += my_strlen(tmp);
        if (stop)
            return info;
    }
    return info;
}
