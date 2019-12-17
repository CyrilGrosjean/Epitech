##
## EPITECH PROJECT, 2019
## makefile
## File description:
## nothing
##

SRC =	my_printf.c				\
		my_put_base.c			\
		my_put_long.c			\
		my_put_nbr.c			\
		my_put_nonprintable.c	\
		my_put_short.c			\
		my_putchar.c			\
		my_putstr.c				\
		my_revstr.c				\
		my_strlen.c				\
		my_put_pointer.c		\

SRC_TEST =	tests/test_my_printf.c	\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

TEST_NAME = unit_tests

TEST_FLAGS = -lcriterion --coverage

all: $(NAME)

$(NAME):	$(OBJ)
			ar rc libmy.a $(OBJ)

clean:
		rm -rf $(OBJ)
		rm -rf *.gc*
		rm -rf tests/*.gc*

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(TEST_NAME)

re:		fclean all

tests_run:	$(TEST_NAME)

$(TEST_NAME):
				gcc $(SRC) $(SRC_TEST) -o $(TEST_NAME) $(TEST_FLAGS)