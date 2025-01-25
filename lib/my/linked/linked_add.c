/*
** EPITECH PROJECT, 2025
** linked_add.c
** File description:
** Add a node
*/

#include "linked.h"
#include "error.h"
#include "define.h"
#include <stdlib.h>

int linked_add(linked_list_t *linked_list, void *data)
{
    linked_list_t *new_linked_list = NULL;
    int id = -1;

    if (!linked_list)
        return err_prog(PTR_ERR, "In: linked_add", KO);
    new_linked_list = malloc(sizeof(linked_list_t));
    if (!new_linked_list)
        return err_prog(MALLOC_ERR, "In: linked_add", KO);
    new_linked_list->data = data;
    if (linked_list->id_status) {
        for (id = linked_list->id; linked_list->next; id++)
            linked_list = linked_list->next;
        new_linked_list->next = NULL;
    } else
        new_linked_list->next = linked_list->next;
    new_linked_list->id = id + 1;
    new_linked_list->previous = linked_list;
    linked_list->next = new_linked_list;
    return OK;
}
