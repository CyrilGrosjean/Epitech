##
## EPITECH PROJECT, 2020
## Makefile by update_makefile
## File description:
## Makefile auto generated, by Cyril Grosjean version: 1.6.0
##

SRC_MAIN =	./main.cpp		\
			./conversion.cpp 	\

SRC =		./conversion.cpp	\

SRC_TEST =	./tests/test_conversion.cpp	\

CC =	g++

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		my_convert_temp

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
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