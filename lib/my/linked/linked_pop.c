/*
** EPITECH PROJECT, 2025
** linked_add.c
** File description:
** Pop the last node
*/

#include "linked.h"
#include "error.h"
#include <stdlib.h>

int linked_pop(linked_list_t *linked_list)
{
    if (!linked_list)
        return err_prog(PTR_ERR, "In: linked_pop", KO);
    while (linked_list->next)
        linked_list = linked_list->next;
    if (linked_list->previous)
        linked_list->previous->next = NULL;
    free(linked_list);
    return OK;
}
