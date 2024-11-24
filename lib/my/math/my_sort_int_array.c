/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** Sort an array of int
*/

#include "error.h"
#include <stdbool.h>

static int set_sorted_array(int *already_sorted, int *changed,
    int *save_i, int smallest)
{
    ERR_D(PTR_ERR, "In: sort_int_array > set_sorted_array", 0,
    (!already_sorted || !changed || !save_i));
    if (*changed != 1)
        already_sorted[*changed * -1] = 1;
    else
        already_sorted[*save_i] = 1;
    return smallest;
}

static int get_smallest(int *array, int size, int *already_sorted)
{
    bool first = true;
    int changed = 0;
    int smallest;
    int save_i;

    ERR_D(PTR_ERR, "In: sort_int_array > get_smallest", 0, (!already_sorted));
    for (int i = 0; i < size; i++) {
        if (first && already_sorted[i] == 0) {
            smallest = array[i];
            changed = i * -1;
            first = false;
        }
        if (!first && smallest >= array[i] && already_sorted[i] == 0) {
            changed = 1;
            smallest = array[i];
            save_i = i;
        }
    }
    return set_sorted_array(already_sorted, &changed, &save_i, smallest);
}

int my_sort_int_array(int *array, int size)
{
    int sort_array[size];
    int already_sorted[size];

    ERR_D(PTR_ERR, "In: sort_int_array", KO, (!array));
    ERR_D(ARGV_ERR, "In: sort_int_array", KO, (size < 0));
    for (int i = 0; i < size; i++)
        already_sorted[i] = 0;
    for (int i = 0; i < size; i++)
        sort_array[i] = get_smallest(array, size, already_sorted);
    for (int i = 0; i < size; i++)
        array[i] = sort_array[i];
    return 0;
}
