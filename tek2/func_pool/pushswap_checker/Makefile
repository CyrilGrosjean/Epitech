##
## EPITECH PROJECT, 2021
## pushswap_checker
## File description:
## Makefile
##

SRC = ./pushswap.hs \

CC = ghc

NAME = pushswap_checker

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf *.o
	rm -rf *.hi

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re