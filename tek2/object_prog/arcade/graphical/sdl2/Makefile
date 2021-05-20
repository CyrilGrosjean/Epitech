##
## EPITECH PROJECT, 2021
## lib makefile
## File description:
## cpp
##

SRC = 	sdl2.cpp \
		core_sdl.cpp \
		set_asset.cpp \
		../../libraries/Vector.cpp 		\
		../../libraries/Settings.cpp	\
		../../libraries/Object.cpp \
		Menu.cpp \
		Game.cpp \

SRC_O = sdl2.o \
		core_sdl.o					\
		set_asset.o				\
		Vector.o 				\
		Game.o 					\
		Object.o 				\
		Settings.o 				\
		Menu.o \


GPP = g++

CFLAGS = -W -Wall -Wextra -fPIC 

LFLAGS = -lSDL2  -lSDL2_ttf -lSDL2_image 

SHARED = -shared

NAME = arcade_sdl2.so

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p ../../lib
	$(GPP) -c $(SRC) -fPIC
	$(GPP) $(SHARED) -o $(NAME) $(SRC_O) $(LFLAGS)
	mv *.so ../../lib

clean:
	$(RM) $(SRC_O)

fclean: clean
	$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY: all clean fclean re test
