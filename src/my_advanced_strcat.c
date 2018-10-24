/*
** EPITECH PROJECT, 2018
** infin add
** File description:
** my advanced strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_advanced_strcat(char dest, char *src)
{
    char *tmp = my_strdup(src);
    int length = my_strlen(src);
    int i = 0;
    int k = 0;

    free(src);
    src = malloc(sizeof(char) * (length + 2));
    src[0] = dest;
    for (k = 0, i = 1; tmp[k] != '\0'; k++, i++)
        src[i] = tmp[k];
    src[i] = '\0';
    free(tmp);
    return (src);
}