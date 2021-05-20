##
## EPITECH PROJECT, 2021
## cpp
## File description:
## Makefile
##

SRC_MAIN =	main.cpp							\
			Core.cpp							\
			../libraries/Vector.cpp 					\
			../libraries/Settings.cpp 					\

CC =	g++

NAME =		arcade

CFLAGS = -Wall -Wextra -ldl

all:	$(NAME)

$(NAME):
	$(CC) $(SRC_MAIN) $(CFLAGS) -o $(NAME)
	mv arcade ../

clean:
	rm -rf *.o

fclean:	clean
	rm -f lib/*.so
	rm -rf ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re