/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2 && error_handling(av[1]) != 84) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return  (0);
    }
    write(2, "Wrong arguments\n", 16);
    return  (84);
}