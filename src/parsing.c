/*
** EPITECH PROJECT, 2018
** evalexpr
** File description:
** issomthing
*/

#include <unistd.h>
#include "my.h"

char *int_to_string(int nb)
{
    int tmp = nb;
    char *ret = my_strdup("");

    if (nb == 0)
        return ("0");
    if (nb < 0)
        nb *= -1;
    while (nb > 0) {
        ret = my_advanced_strcat((nb % 10) + '0', ret);
        nb /= 10;
    }
    if (tmp < 0)
        ret = my_advanced_strcat('-', ret);
    return (ret);
}

int is_ope(char op)
{
    if (op == '+' || op == '-')
        return (LOW);
    if (op == '*' || op == '/' || op == '%')
        return (MEDIUM);
    if (op == '(' || op == ')')
        return (HIGH);
    return (0);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);    
}