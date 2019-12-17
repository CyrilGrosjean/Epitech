##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	src/main.c				\
			src/my_strlen.c			\
			src/open_file.c			\
			src/window.c			\
			src/animations.c		\
			src/error.c				\
			src/movement.c			\
			src/help.c				\
			src/my_putchar.c		\
			src/my_putstr.c			\
			src/conditions.c		\

SRC	=		src/my_strlen.c			\
			src/open_file.c			\
			src/window.c			\
			src/animations.c		\
			src/error.c				\
			src/movement.c			\
			src/help.c				\
			src/my_putchar.c		\
			src/my_putstr.c			\
			src/conditions.c		\

SRC_TEST = 	tests/test_error.c		\
			tests/test_help.c		\
			tests/test_conditions.c	\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		my_sokoban

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(CFLAGS) $(OBJ_MAIN) -o $(NAME) -lncurses

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
				gcc $(TEST_FLAG) $(SRC) $(SRC_TEST) -lncurses -o $(TEST_NAME)
				./$(TEST_NAME)