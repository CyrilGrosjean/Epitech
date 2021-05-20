##
## EPITECH PROJECT, 2021
## cpp
## File description:
## Makefile
##

all:
	make -C ncurses
	make -C sdl2
	make -C sfml

clean:
	make clean -C ncurses
	make clean -C sdl2
	make clean -C sfml

fclean:	clean
	make fclean -C ncurses
	make fclean -C sdl2
	make fclean -C sfml

re:	fclean all

.PHONY:	all clean fclean re