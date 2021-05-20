##
## EPITECH PROJECT, 2021
## groundhog
## File description:
## Makefile
##

SRC = groundhog.py

NAME = groundhog

RM = rm -rf

all: $(NAME)

$(NAME):
	cp $(SRC) ./$(NAME)
	chmod 777 $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re