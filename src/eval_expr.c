/*
** EPITECH PROJECT, 2018
** eval expr
** File description:
** main functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void operator_shunting(char *expr, list_t **eval, char **tok)
{
    int op = is_ope(*expr);

    if (*expr == ')') {
        while (**tok != '(') {
            my_put_in_list_queue(eval, my_advanced_strcat(**tok, my_strdup("")));
            *tok += 1;
        }
        *tok += 1;
    }
    else if (**tok == '\0' || *expr == '(' || is_ope(**tok) < op)
        *tok = my_advanced_strcat(*expr, *tok);
    else {
        my_put_in_list_queue(eval, my_advanced_strcat(**tok, my_strdup("")));
        *tok = my_strdup(*tok + 1);
        *tok = my_advanced_strcat(*expr, *tok);
    }
}

void shunting_yard(char *expr, list_t **eval, char *tok)
{
    char *nbr = NULL;

    while (*expr != '\0') {
        if (is_num(*expr) == 1) {
            nbr = int_to_string(my_getnbr(expr));
            my_put_in_list_queue(eval, nbr);
            expr = expr + my_strlen(nbr);
        }
        else {
            operator_shunting(expr, eval, &tok);
            expr = expr + 1;
        }
    }
    while (*tok != '\0') {
        my_put_in_list_queue(eval, my_advanced_strcat(*tok, my_strdup("")));
        tok += 1;
    }
    return;
}

ptr_fct_t *init_ptr_fct(ptr_fct_t *ptr)
{
    ptr = malloc(sizeof(*ptr) * 5);
    ptr[0].op = my_strdup("+");
    ptr[0].ptr_fct = &my_add;
    ptr[1].op = my_strdup("-");
    ptr[1].ptr_fct = &my_sub;
    ptr[2].op = my_strdup("*");
    ptr[2].ptr_fct = &my_mul;
    ptr[3].op = my_strdup("/");
    ptr[3].ptr_fct = &my_div;
    ptr[4].op = my_strdup("%");
    ptr[4].ptr_fct = &my_mod;
    return (ptr);
}

int make_my_calc(list_t *eval, ptr_fct_t *ptr, int res)
{
    list_t *tmp = eval;
    int i = 0;
    int a = 0;
    int b = 0;

    if (tmp->next == NULL && tmp->prev == NULL)
        return (res);
    while (is_num(tmp->data[0]) == 1 || tmp->data[1] != '\0')
        tmp = tmp->next;
    a = my_getnbr(tmp->prev->prev->data);
    b = my_getnbr(tmp->prev->data);
    while (i != 5) {
        if (my_strcmp(tmp->data, ptr[i].op) == 0)
            res = ptr[i].ptr_fct(a, b);
        i += 1;
    }
    tmp->data = int_to_string(res);
    tmp = delete_node(tmp);
    res = make_my_calc(tmp, ptr, res);
    return (res);
}

int eval_expr(char *expr)
{
    ptr_fct_t *ptr = NULL;
    list_t *eval = NULL;
    char *tok = my_strdup("");
    int res = 0;

    ptr = init_ptr_fct(ptr);
    shunting_yard(expr, &eval, tok);
    res = make_my_calc(eval, ptr, res);
    return (res);
}