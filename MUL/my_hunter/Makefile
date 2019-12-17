##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC = 	src/main.c				\
		src/init.c				\
		src/get_event.c			\
		src/sprite.c			\
		src/destroy.c			\
		src/clock.c				\
		src/window.c			\
		src/ambiance_sound.c	\
		src/error.c				\
		src/text.c				\
		src/mouse_click.c		\
		src/int_to_str.c		\
		src/heart_sprite.c		\
		src/my_putchar.c		\
		src/my_putstr.c			\
		src/doc.c				\

OBJ = 	$(SRC:.c=.o)

NAME =	my_hunter

CFLAGS = -W -Wextra -Wall -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all