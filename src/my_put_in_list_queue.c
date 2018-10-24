/*
** EPITECH PROJECT, 2018
** my_put_in_list_queue
** File description:
** queued
*/

#include <stdlib.h>
#include "my.h"

void my_put_in_list_queue(list_t **list, char *data)
{
    list_t *tmp = *list;
    list_t *elem = malloc(sizeof(*elem));

    elem->data = data;
    elem->next = NULL;
    elem->prev = NULL;
    if (tmp == NULL)
    	*list = elem;
    else {
        while (tmp->next != NULL)
	        tmp = tmp->next;
            elem->prev = tmp;
            tmp->next = elem;
    }
}
