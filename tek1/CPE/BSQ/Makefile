##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	main.c				\
			my_bsq.c 			\
			my_getnbr.c			\
			my_putchar.c		\
			my_putstr.c			\
			dimensions.c		\
			check_square.c		\
			make_square.c		\

SRC	=		my_bsq.c 			\
			my_getnbr.c			\
			my_putchar.c		\
			my_putstr.c			\
			dimensions.c		\
			check_square.c		\
			make_square.c		\

SRC_TEST = 	tests/test_my_bsq.c			\
			tests/test_my_bsqbranch.c	\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		bsq

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(CFLAGS) $(OBJ_MAIN) -o $(NAME)

clean :
			rm -rf $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf $(TEST_NAME)

re :		fclean all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./$(TEST_NAME)