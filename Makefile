##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC 	=	src/main.c			\
			src/my_getnbr.c		\
			src/my_putstr.c 	\
			src/my_put_nbr.c 	\
			src/my_printf.c		\
			src/errors.c 		\
			src/ai.c 			\

OBJ 	= 	$(SRC:.c=.o)

NAME	=	matchstick

CC = gcc -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

test_run:
		$(CC) -o unit_test bonus/testcriterion.c $(SRC) -lcriterion
		./unit_test

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
