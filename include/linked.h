/*
** EPITECH PROJECT, 2025
** linked.h
** File description:
** Header for the linked
*/

#ifndef LINKED_H
    #define LINKED_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stdbool.h> // boolean

//----------------------------------------------------------------//
/* PROTOTYPE */

/* linked */
typedef struct linked_list_s {
    bool id_status;
    int id;
    void *data;
    struct linked_list_s *previous;
    struct linked_list_s *next;
} linked_list_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* gestion */ // Error: KO
int linked_add(linked_list_t *linked_list, void *data);
int linked_add_id(linked_list_t **linked_list, void *data, int id);
int linked_pop(linked_list_t *linked_list);
int linked_pop_id(linked_list_t **linked_list, int id);

/* get_info */
void *linked_get_data(linked_list_t *linked_list, int id); // Error: NULL

#endif /* LINKED_H */
