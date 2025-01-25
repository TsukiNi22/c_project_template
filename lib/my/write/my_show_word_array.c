/*
** EPITECH PROJECT, 2025
** my_show_word_array.c
** File description:
** Show the tab given
*/

#include "string.h"
#include "write.h"
#include "error.h"
#include <unistd.h>

int my_show_word_array(char const **array)
{
    if (!array)
        return err_prog(PTR_ERR, "In: show_word_array 1", KO);
    for (int i = 0; array[i]; i++) {
        if (my_putstr(1, array[i]) == KO || write(1, "\n", 1) != 1)
            return err_prog(WRITE_ERR, "In: show_word_array", KO);
    }
    return OK;
}
