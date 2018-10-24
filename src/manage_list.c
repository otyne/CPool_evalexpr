/*
** EPITECH PROJECT, 2018
** eval expr
** File description:
** manae list
*/

#include <unistd.h>
#include "my.h"

list_t *delete_node(list_t *list)
{
    list_t *tmp = list;

    if (list->prev->prev->prev == NULL) {
        list->prev = NULL;
        return (list);
    } else {
        tmp = list->prev->prev->prev;
        tmp->next = list;
        list->prev = tmp;
    }
    while (list->prev != NULL)
        list = list->prev;
    return (list);
}

void my_show_list(list_t *list)
{
    while (list->next != NULL) {
        my_putstr(list->data);
        my_putchar('\t');
        list = list->next;
    }
    my_putstr(list->data);
    my_putchar('\n');
    // while (list->prev != NULL) {
    //     my_putstr(list->data);
    //     my_putchar('\t');
    //     list = list->prev;
    // }
    // my_putstr(list->data);
    // my_putchar('\n');
}
