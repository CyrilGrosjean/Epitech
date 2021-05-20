##
## EPITECH PROJECT, 2020
## Makefile by update_makefile
## File description:
## Makefile auto generated, by Cyril Grosjean version: 1.6.0
##

SRC_MAIN =	$(filter-out main.c, $(wildcard *.c))\

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		libstring.a

CFLAGS = -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libstring.a $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf unit_tests
	rm -rf *.gc*

re:	fclean all

SRC_TEST = $(filter-out main.c, $(wildcard tests/test*.c))\

TEST_NAME =    unit_tests

TEST_FLAG = -lcriterion --coverage

tests_run:    $(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC_MAIN)
	gcc -o $(TEST_NAME) $(SRC_MAIN) $(SRC_TEST) $(TEST_FLAG)
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

.PHONY:	all clean fclean re