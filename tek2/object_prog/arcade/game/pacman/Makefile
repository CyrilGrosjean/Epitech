
##
## EPITECH PROJECT, 2021
## lib makefile
## File description:
## cpp
##

SRC = 	pacman.cpp 						\
		game/Pacman.cpp					\
		exceptions/PacmanException.cpp	\
		../../libraries/Vector.cpp		\
		../../libraries/Settings.cpp		\
		../../libraries/Object.cpp		\



SRC_O = pacman.o			\
		Pacman.o			\
		PacmanException.o	\
		Vector.o			\
		Settings.o \
		Object.o

GPP = g++

CFLAGS = -W -Wall -Wextra -fPIC

SHARED = -shared

NAME = arcade_pacman.so

all: $(NAME)

$(NAME): $(SRC_O)
	mkdir -p ../../lib
	$(GPP) $(SHARED) -o $(NAME) $(SRC_O)
	mv *.so ../../lib

%.o: %.cpp
	$(GPP) -c $(SRC) -fPIC

clean:
	$(RM) $(SRC_O)

fclean: clean
	$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re test