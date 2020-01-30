##
## EPITECH PROJECT, 2019
## Makefile by update_makefile
## File description:
## Makefile auto generated, program by MrUrica
##

SRC_MAIN =	./src/game.c	\
			./src/my_put_nbr.c	\
			./src/display_board.c	\
			./src/main.c	\
			./src/my_getnbr.c	\
			./src/check_player_move.c	\
			./src/display_text.c	\
			./src/remove_stick.c	\
			./src/get_game_params.c	\
			./src/bot/bot.c	\
			./src/bot/bot_strategy.c	\
			./src/bot/set_matchstick_array.c	\
			./src/bot/play.c	\

SRC =		./src/game.c	\
			./src/my_put_nbr.c	\
			./src/display_board.c	\
			./src/my_getnbr.c	\
			./src/check_player_move.c	\
			./src/display_text.c	\
			./src/remove_stick.c	\
			./src/get_game_params.c	\
			./src/bot/bot.c	\
			./src/bot/bot_strategy.c	\
			./src/bot/set_matchstick_array.c	\
			./src/bot/play.c	\

SRC_TEST =	./tests/test_my_putnbr.c	\
			./tests/test_display_board.c	\
			./tests/test_remove_stick.c	\
			./tests/test_display_text.c	\
			./tests/test_check_error_match.c	\
			./tests/test_get_game_params.c	\
			./tests/test_game.c	\
			./tests/test_check_line_error.c	\

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		matchstick

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wextra -Wall -C

DEBUG_FLAGS = -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

debug:	$(OBJ)
	gcc $(DEBUG_FLAGS) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf *.gc*
	rm -rf tests/*.gc*

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re:	fclean all

tests_run:	$(SRC_TEST) $(SRC)
				gcc $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./$(TEST_NAME)