##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	src/main.c				\
			src/make_list.c			\
			src/sort.c				\
			src/rotate.c			\
			src/swap_elem.c			\
			src/my_putstr.c			\
			src/my_putchar.c		\
			src/switch.c			\

SRC	=		src/make_list.c			\
			src/sort.c				\
			src/rotate.c			\
			src/swap_elem.c			\
			src/my_putstr.c			\
			src/my_putchar.c		\
			src/switch.c			\

SRC_TEST =	tests/test_make_list.c	\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		push_swap

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
