/*
** EPITECH PROJECT, 2025
** linked_pop.c
** File description:
** Add a node at id
*/

#include "linked.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static int deincrement(linked_list_t *actual_linked_list)
{
    if (!actual_linked_list)
        return err_prog(PTR_ERR, "In: linked_pop_id > deincrement", KO);
    while (actual_linked_list->next) {
        actual_linked_list->id--;
        actual_linked_list = actual_linked_list->next;
    }
    actual_linked_list->id--;
    return OK;
}

static int linked_pop_start(linked_list_t **linked_list)
{
    linked_list_t *tmp_linked_list = NULL;

    if (!linked_list || !(*linked_list))
        return err_prog(PTR_ERR, "In: linked_pop_id > linked_pop_start", KO);
    tmp_linked_list = (*linked_list)->next;
    free((*linked_list));
    if (tmp_linked_list) {
        (*linked_list) = tmp_linked_list;
        deincrement((*linked_list));
    }
    return OK;
}

static int linked_pop_end(linked_list_t *actual_linked_list)
{
    if (!actual_linked_list)
        return err_prog(PTR_ERR, "In: linked_pop_id > linked_pop_end", KO);
    if (actual_linked_list->previous)
        actual_linked_list->previous->next = NULL;
    free(actual_linked_list);
    return OK;
}

static int linked_pop_at(linked_list_t *actual_linked_list)
{
    if (!actual_linked_list)
        return err_prog(PTR_ERR, "In: linked_pop_id > linked_pop_at", KO);
    actual_linked_list->previous->next = actual_linked_list->next;
    actual_linked_list->next->previous = actual_linked_list->previous;
    deincrement(actual_linked_list);
    free(actual_linked_list);
    return OK;
}

int linked_pop_id(linked_list_t **linked_list, int id)
{
    linked_list_t *actual_linked_list = NULL;

    if (!linked_list || !(*linked_list))
        return err_prog(PTR_ERR, "In: linked_pop_id", KO);
    actual_linked_list = *linked_list;
    if ((*linked_list)->id >= id)
        return linked_pop_start(linked_list);
    while (actual_linked_list->next && actual_linked_list->id < id)
        actual_linked_list = actual_linked_list->next;
    if (!actual_linked_list->next && actual_linked_list->id <= id)
        return linked_pop_end(actual_linked_list);
    return linked_pop_at(actual_linked_list);
}
