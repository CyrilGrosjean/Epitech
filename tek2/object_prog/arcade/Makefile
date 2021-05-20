##
## EPITECH PROJECT, 2021
## cpp
## File description:
## Makefile
##

all:
	make -C graphical
	make -C game
	make -C cores

core:
	make -C cores

games:
	make -C game

graphicals:
	make -C graphical

clean:
	make clean -C graphical
	make clean -C game
	make clean -C cores

fclean:	clean
	make fclean -C graphical
	make fclean -C game
	make fclean -C cores

re:	fclean all

.PHONY:	all clean fclean re