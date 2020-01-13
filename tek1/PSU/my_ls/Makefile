##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	src/main.c				\
			src/my_ls.c				\
			src/my_strlen.c			\
			src/my_putstr.c			\
			src/str_copy.c			\
			src/display.c			\
			src/fill_struct.c		\
			src/get_stats.c			\
			src/free.c				\
			src/apply_flag.c		\
			src/my_put_nbr.c		\
			src/flag_l.c			\
			src/get_path_name.c		\
			src/sort_time.c			\

SRC	=		src/my_ls.c				\
			src/my_strlen.c			\
			src/my_putstr.c			\
			src/str_copy.c			\
			src/display.c			\
			src/fill_struct.c		\
			src/get_stats.c			\
			src/free.c				\
			src/apply_flag.c		\
			src/my_put_nbr.c		\
			src/flag_l.c			\
			src/get_path_name.c		\
			src/sort_time.c			\

SRC_TEST =	tests/test_flags.c		\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		my_ls

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