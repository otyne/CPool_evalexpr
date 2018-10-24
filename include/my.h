/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** lib.h
*/

#ifndef MY_H_
#define MY_H_

/* STRUCTS & ENUMS */

enum priority
{
    HIGH = -1,
    MEDIUM = 2,
    LOW = 1,
};

typedef struct s_ptr_fct
{
    char *op;
    int (*ptr_fct)(int, int);
} ptr_fct_t;

typedef struct s_list
{
    char *data;
    struct s_list *prev;
    struct s_list *next;
} list_t;

/* PROG FUNCS */

list_t *delete_node(list_t *);
int my_add(int, int);
int my_sub(int, int);
int my_mul(int, int);
int my_div(int, int);
int my_mod(int, int);
void my_show_list(list_t *);
int eval_expr(char *);
int is_num(char);
int is_ope(char);
int error_handling(char *);
char *int_to_string(int);
void my_put_in_list_queue(list_t **, char *);
void my_put_in_list_head(list_t **, char *);
char *my_advanced_strcat(char, char *);


/* LIB FUNCS */

void my_putchar(char);
int my_putstr(char *);
int my_put_nbr(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char *);
int my_str_isnum(char *);
int my_str_islower(char *);
int my_str_isupper(char *);
int my_str_isprintable(char *);
int my_putnbr_base(int, char const *);
int my_getnbr_base(char const *, char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
void my_print_params(int, char **);
void my_rev_params(int, char **);
void my_sort_params(int, char **);
int my_strlen(char *);
int my_getnbr(char*);
char *my_strdup(char const *);

#endif
