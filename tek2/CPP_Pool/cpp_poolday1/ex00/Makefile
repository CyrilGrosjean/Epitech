##
## EPITECH PROJECT, 2020
## Makefile by update_makefile
## File description:
## Makefile auto generated, by Cyril Grosjean version: 1.6.0
##

SRC_MAIN =	./z.c	\

SRC =		./z.c	\

SRC_TEST =	./tests/test_z.c	\

CC =	gcc

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		z

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -Wall -Wextra -std=gnu11

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf *.gc*
	rm -rf tests/*.gc*

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re:	fclean all

tests_run:	$(SRC_TEST) $(SRC)
			$(CC) $(SRC) $(SRC_TEST) $(TEST_FLAG) -o $(TEST_NAME)
			./$(TEST_NAME)
			gcovr --exclude tests/
			gcovr -b --exclude tests/

.PHONY:	all clean fclean re