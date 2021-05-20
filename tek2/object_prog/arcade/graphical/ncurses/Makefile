##
## EPITECH PROJECT, 2021
## lib makefile
## File description:
## cpp
##

SRC = 	ncurses.cpp						\
		Ncurses.cpp						\
		../../libraries/Vector.cpp 		\
		../../libraries/Settings.cpp	\
		../../libraries/Object.cpp 		\

SRC_O = ncurses.o		\
		Ncurses.o		\
		Vector.o		\
		Settings.o		\
		Object.o		\

GPP = g++

CFLAGS = -W -Wall -Wextra -fPIC

LFLAGS = -lncurses

SHARED = -shared

NAME = arcade_ncurses.so

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
