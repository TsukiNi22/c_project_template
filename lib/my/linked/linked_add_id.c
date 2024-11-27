/*
** EPITECH PROJECT, 2024
** linked_add.c
** File description:
** Add a node at id
*/

#include "linked.h"
#include "typedef.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static int increment(linked_list_t *actual_linked_list)
{
    ERR_D(PTR_ERR, "In: linked_add_id > increment", KO,
    (!actual_linked_list));
    while (actual_linked_list->next) {
        actual_linked_list->id++;
        actual_linked_list = actual_linked_list->next;
    }
    actual_linked_list->id++;
    return OK;
}

static int linked_add_start(linked_list_t **linked_list,
    linked_list_t *new_linked_list, bool before)
{
    linked_list_t *actual_linked_list;

    ERR_D(PTR_ERR, "In: linked_add_id > linked_add_start", KO,
    (!linked_list || !(*linked_list) || !new_linked_list));
    new_linked_list->id = (*linked_list)->id - before;
    new_linked_list->previous = NULL;
    new_linked_list->next = *linked_list;
    actual_linked_list = *linked_list;
    actual_linked_list->previous = new_linked_list;
    if (!before)
        increment(actual_linked_list);
    (*linked_list) = new_linked_list;
    return OK;
}

static int linked_add_at(linked_list_t *actual_linked_list,
    linked_list_t *new_linked_list, int l_id, bool after)
{
    linked_list_t *tmp_linked_list;

    ERR_D(PTR_ERR, "In: linked_add_id > linked_add_at", KO,
    (!actual_linked_list || !new_linked_list));
    new_linked_list->id = l_id + after;
    if (!after)
        tmp_linked_list = actual_linked_list->previous;
    else
        tmp_linked_list = actual_linked_list;
    tmp_linked_list->next = new_linked_list;
    new_linked_list->previous = tmp_linked_list;
    if (!after)
        actual_linked_list->previous = new_linked_list;
    new_linked_list->next = NULL;
    if (!after) {
        new_linked_list->next = actual_linked_list;
        increment(actual_linked_list);
    }
    return OK;
}

int linked_add_id(linked_list_t **linked_list, void *data, int id)
{
    linked_list_t *new_linked_list;
    linked_list_t *actual_linked_list;
    int l_id;

    ERR_D(PTR_ERR, "In: linked_add_id", KO, (!linked_list || !(*linked_list)));
    actual_linked_list = *linked_list;
    new_linked_list = malloc(sizeof(linked_list_t));
    ERR_D(MALLOC_ERR, "In: linked_add_id", KO, (!new_linked_list));
    new_linked_list->data = data;
    if ((*linked_list)->id >= id)
        return linked_add_start(linked_list, new_linked_list,
        (*linked_list)->id > id);
    for (l_id = actual_linked_list->id; actual_linked_list->next &&
        actual_linked_list->id < id; l_id++)
        actual_linked_list = actual_linked_list->next;
    return linked_add_at(actual_linked_list, new_linked_list, l_id,
    actual_linked_list->id < id);
}
