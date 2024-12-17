/*
** EPITECH PROJECT, 2024
** linked_add.c
** File description:
** Add a node
*/

#include "typedef.h"
#include "linked.h"
#include "error.h"
#include "define.h"
#include <stdlib.h>

int linked_add(linked_list_t *linked_list, void *data)
{
    linked_list_t *new_linked_list = NULL;
    int id = 0;

    if (!linked_list)
        return err_prog(PTR_ERR, "In: linked_add", KO);
    new_linked_list = malloc(sizeof(linked_list_t));
    if (!new_linked_list)
        return err_prog(MALLOC_ERR, "In: linked_add", KO);
    new_linked_list->data = data;
    for (id = linked_list->id; linked_list->next; id++)
        linked_list = linked_list->next;
    new_linked_list->id = id + 1;
    new_linked_list->previous = linked_list;
    new_linked_list->next = NULL;
    linked_list->next = new_linked_list;
    return OK;
}
