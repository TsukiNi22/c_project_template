/*
** EPITECH PROJECT, 2024
** linked_add.c
** File description:
** Pop the last node
*/

#include "typedef.h"
#include "linked.h"
#include "error.h"
#include <stdlib.h>

int linked_pop(linked_list_t *linked_list)
{
    ERR_D(PTR_ERR, "In: linked_pop", KO, (!linked_list));
    while (linked_list->next)
        linked_list = linked_list->next;
    if (linked_list->previous)
        linked_list->previous->next = NULL;
    free(linked_list);
    return OK;
}
