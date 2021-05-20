##
## EPITECH PROJECT, 2020
## Makefile by update_makefile
## File description:
## Makefile auto generated, by Cyril Grosjean version: 1.6.0
##

SRC_MAIN =	./bitmap_header.c	\
			./main.c	\
			./menger.c	\
			./drawing.c	\

CC =	gcc

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		menger_face

CFLAGS = -Wall -Wextra -std=gnu11

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re