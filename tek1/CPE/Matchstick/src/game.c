/*
** EPITECH PROJECT, 2020
** game
** File description:
** game function
*/

#include "../include/matchstick.h"

int check_end(int *tab, game_t *params)
{
    for (int i = 0; i < params->lines; i += 1)
        if (tab[i] != 0)
            return (0);
    return (1);
}

int player_turn(int *tab, game_t *param)
{
    int line = 0;
    int stick = 0;
    char *choice = malloc(sizeof(char) * 10);
    size_t size = 10;

    while (1) {
        my_putstr(1, "Line: ");
        if (getline(&choice, &size, stdin) == EOF)
            return (0);
        line = my_getnbr(choice);
        if (!check_line_error(param, line, choice)) {
            if (getline(&choice, &size, stdin) == EOF)
                return (0);
            stick = my_getnbr(choice);
            if (!check_error_match(param, tab, choice, line))
                break;
        }
    }
    free(choice);
    remove_stick_player(tab, line, stick);
    return (2);
}

int in_game(int *tab, game_t *params)
{
    int lose = 0;

    display_board(tab, params);
    while (1) {
        my_putstr(1, "\nYour turn:\n");
        lose = player_turn(tab, params);
        if (lose == 0)
            break;
        display_board(tab, params);
        if (check_end(tab, params))
            break;
        my_putstr(1, "\nAI's turn...\n");
        lose = bot_play(tab, params);
        display_board(tab, params);
        if (check_end(tab, params))
            break;
    }
    free(tab);
    return (lose);
}