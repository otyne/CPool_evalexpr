/*
** EPITECH PROJECT, 2018
** evalexpr
** File description:
** errors handling
*/

#include <stdlib.h>
#include "my.h"

int parenthesis(char *expr)
{
    int i = 0;
    int k = 0;
    int p = 0;

    while (expr[i] != '\0') {
        p += (expr[i] == '(' && p == 0) ? 1 : 0;
        k = i;
        while (expr[k] != '\0' && p == 1) {
            p -= (expr[k] == ')') ? 1 : 0;
            expr[k] = (expr[k] == ')') ? 'k' : expr[k];
            k += 1;
        }
        p -= (expr[i] == ')') ? 1 : 0;
        i += 1;
    }
    if (p == 0)
        return (0);
    else
        return (84);
}

int error_handling(char *expr)
{
    char *tmp = my_strdup(expr);
    int i = 0;

    while (expr[i] != '\0') {
        if ((expr[i] < '0' || expr[i] > '9') && is_ope(expr[i]) == 0)
            return (84);
        i += 1;
    }
    if (parenthesis(tmp) == 84)
        return (84);
    free(tmp);
    return (0);
}