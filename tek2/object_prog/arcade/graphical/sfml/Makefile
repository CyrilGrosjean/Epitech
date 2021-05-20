##
## EPITECH PROJECT, 2021
## lib makefile
## File description:
## cpp
##

SRC = 	sfml.cpp						\
		Sfml.cpp						\
		MainMenu.cpp					\
		Sprite.cpp						\
		Text.cpp						\
		Input.cpp						\
		Button.cpp						\
		Game.cpp 						\
		../../libraries/Vector.cpp 		\
		../../libraries/Settings.cpp	\
		../../libraries/Object.cpp 		\


SRC_O =	sfml.o					\
		Sfml.o					\
		MainMenu.o				\
		Sprite.o 				\
		Text.o 					\
		Input.o 				\
		Button.o 				\
		Vector.o 				\
		Game.o 					\
		Object.o 				\
		Settings.o 				\

GPP = g++

CFLAGS = -W -Wall -Wextra -fPIC

LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SHARED = -shared

NAME = arcade_sfml.so

all: $(NAME)

$(NAME): $(SRC_O)
	$(GPP) $(SHARED) -o $(NAME) $(SRC_O) $(LFLAGS)
	mv *.so ../../lib

%.o: %.cpp
	$(GPP) -c $(SRC) -fPIC

clean:
	$(RM) $(SRC_O)

fclean: clean
	$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re test
