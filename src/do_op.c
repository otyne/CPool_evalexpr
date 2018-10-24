/*
** EPITECH PROJECT, 2018
** eval expr
** File description:
** do_op
*/

#include "my.h"

int my_add(int a, int b)
{
    return (a + b);
}

int my_sub(int a, int b)
{
    return (a - b);
}

int my_mul(int a, int b)
{
    return (a * b);
}

int my_div(int a, int b)
{
    if (b == 0) {
        my_putstr("Infinity\n");
        return (0);
    }
    return (a / b);
}

int my_mod(int a, int b)
{
    if (b == 0) {
        my_putstr("Infinity\n");
        return (0);
    }
    return (a % b);
}