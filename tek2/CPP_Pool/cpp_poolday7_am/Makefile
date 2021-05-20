##
## EPITECH PROJECT, 2019
## RUSH1 UT
## File description:
## UT
##

SRC	=

SRC_TEST =	tests/Federation_test.cpp \
			tests/Borg_test.cpp \
			Borg.cpp \
			Federation.cpp \
			WarpSystem.cpp \

OBJ	=	$(SRC:.c=.o)

NAME	=	test.a

NAME_TEST	= 	unit_tests

CFLAGS 	=	-W -Wall -Werror -Wextra -g

UTFLAGS =       -l criterion --coverage

RM	=	rm -rf

all:		tests_run

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

tests_run:
	$(RM) *.gcda *.gcno
	$(RM) unit_test.dSYM
	g++ -o $(NAME_TEST) $(UTFLAGS) $(SRC_TEST) $(CFLAGS) -I./tests/
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
		$(RM) $(OBJ)

fclean :	clean
		$(RM) $(NAME)
		$(RM) $(NAME_TEST)
		$(RM) *.gcda *.gcno
		$(RM) unit_test.dSYM

re:		fclean all