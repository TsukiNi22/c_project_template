/*
** EPITECH PROJECT, 2024
** get_fullpath.c
** File description:
** Cat tow system path
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"

char *get_full_path(char const *cr_path, char const *file)
{
    char *path = NULL;
    int len_1;
    int len_2;
    int len_3;

    ERR_DN(PTR_ERR, "In: get_full_path", (!cr_path || !file));
    len_1 = my_strlen(cr_path);
    len_2 = my_strlen(file);
    ERR_DN(UNDEF_ERR, "In: get_full_path 1", (len_1 < 0 || len_2 < 0));
    ERR_DN(UNDEF_ERR, "In: get_full_path 2",
    (my_malloc_c(&path, len_1 + len_2 + 2) == KO));
    ERR_DN(UNDEF_ERR, "In: get_full_path 3", (!my_strcat(path, cr_path)));
    len_3 = my_strlen(path);
    ERR_DN(UNDEF_ERR, "In: get_full_path 4", (len_3 < 0));
    if (path[len_3 - 1] != '/')
        ERR_DN(UNDEF_ERR, "In: get_full_path 5", (!my_strcat(path, "/\0")));
    ERR_DN(UNDEF_ERR, "In: get_full_path 5", (!my_strcat(path, file)));
    return path;
}
