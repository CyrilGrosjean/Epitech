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
			src/consoles_window.c	\
			src/display_main_menu.c	\
			src/display_editor.c	\
			src/my_int_to_str.c		\
			src/my_revstr.c			\
			src/save_file.c			\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		my_sokoban

CFLAGS = -W -Wall -Wextra -C -g3

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(CFLAGS) $(OBJ_MAIN) -o $(NAME) -lncurses

clean :
			rm -rf $(OBJ_MAIN)

fclean :	clean
			rm -rf $(NAME)

re :		fclean all