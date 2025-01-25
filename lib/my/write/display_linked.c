/*
** EPITECH PROJECT, 2025
** display_linked.c
** File description:
** Display the content of the linked list
*/

#include "write.h"
#include "linked.h"
#include "error.h"

int display_linked(linked_list_t *linked_list)
{
    if (!linked_list)
        return err_prog(PTR_ERR, "In: display_linked", KO);
    while (linked_list) {
        my_putstr(1, "Id: ");
        my_putnbr(linked_list->id);
        my_putstr(1, "\nPtr Data: 0x");
        my_putnbr_base((unsigned long long) linked_list->data,
        "0123456789abcdef");
        my_putstr(1, "\nPtr Previous: 0x");
        my_putnbr_base((unsigned long long) linked_list->previous,
        "0123456789abcdef");
        my_putstr(1, "\nPtr Next: 0x");
        my_putnbr_base((unsigned long long) linked_list->next,
        "0123456789abcdef");
        my_putchar('\n');
        linked_list = linked_list->next;
    }
    return OK;
}
