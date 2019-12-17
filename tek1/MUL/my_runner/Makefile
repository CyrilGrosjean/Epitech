##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC = 	src/main.c				\
		src/prepare_window.c	\
		src/runner.c			\
		src/parallax_update.c	\
		src/sprite_update.c		\
		src/event.c				\
		src/destroy.c			\
		src/prepare_map.c		\
		src/map_reader.c		\
		src/str_change.c		\
		src/my_putstr_error.c	\
		src/text.c				\
		src/music.c				\
		src/reset.c				\

OBJ = 	$(SRC:.c=.o)

NAME =	my_runner

CFLAGS = -W -Wextra -Wall -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all