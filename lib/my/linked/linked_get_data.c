/*
** EPITECH PROJECT, 2024
** linked_add.c
** File description:
** Get the data of the given id
*/

#include "define.h"
#include "linked.h"
#include "error.h"

void *linked_get_data(linked_list_t *linked_list, int id)
{
    if (!linked_list)
        return err_prog_n(PTR_ERR, "In: linked_get_data");
    if (linked_list->id > id)
        return NULL;
    while (linked_list->next && linked_list->id != id)
        linked_list = linked_list->next;
    if (linked_list->id != id)
        return NULL;
    return linked_list->data;
}
