/*
** EPITECH PROJECT, 2024
** my_show_word_array.c
** File description:
** Show the tab given
*/

#include "char.h"
#include "include.h"
#include "error.h"
#include "write.h"

int my_show_word_array(char const **tab)
{
    if (!tab)
        return err_dispatch(PTR_ERR, "In: show_word_array 1", KO);
    for (int i = 0; tab[i]; i++) {
        if (!tab[i])
            return err_dispatch(PTR_ERR, "In: show_word_array 2", KO);
        if (my_putstr(1, tab[i]) == KO || write(1, "\n", 1) != 1)
            return err_dispatch(WRITE_ERR, "In: show_word_array", KO);
    }
    return 0;
}
