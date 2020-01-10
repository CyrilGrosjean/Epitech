##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		get_next_line.c				\

SRC_TEST = 	tests/test_get_next_line.c	\

NAME =		get_next_line

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3

clean :
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