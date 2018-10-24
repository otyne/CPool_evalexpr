##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)main.c			\
		$(SRC_DIR)errors.c			\
		$(SRC_DIR)eval_expr.c			\
		$(SRC_DIR)parsing.c			\
		$(SRC_DIR)my_put_in_list_head.c		\
		$(SRC_DIR)my_put_in_list_queue.c	\
		$(SRC_DIR)my_advanced_strcat.c		\
		$(SRC_DIR)manage_list.c			\
		$(SRC_DIR)do_op.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -Llib/my -lmy -Iinclude

NAME	=	eval_expr

all:	$(OBJ)
	@make -sC ./lib/my
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@make -sC ./lib/my clean
	@make -sC ./tests clean
	@rm -f $(OBJ)

fclean:	clean
	@make -sC ./lib/my fclean
	@make -sC ./tests fclean
	@rm -f $(NAME)

tests_run:
	@make -sC ./lib/my
	@make -sC ./tests
	./tests/units-tests

re:	fclean all
