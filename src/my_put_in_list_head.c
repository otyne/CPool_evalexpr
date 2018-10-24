/*
** EPITECH PROJECT, 2018
** put in list
** File description:
** put in list
*/

#include <stdlib.h>
#include "my.h"

void my_put_in_list_head(list_t **list, char *data)
{
    list_t *tmp = *list;
    list_t *elem;

    elem = malloc(sizeof(*elem));
    elem->data = data;
    elem->next = NULL;
    if (tmp != NULL)
        elem->next = *list;
    *list = elem;
}
