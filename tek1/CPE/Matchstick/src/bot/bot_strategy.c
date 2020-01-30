/*
** EPITECH PROJECT, 2020
** bot strategy
** File description:
** functions for bot strategy
*/

#include "../../include/matchstick.h"

int get_number_stick(stick_t *stick, game_t *param)
{
    int nb_stick = param->matches;

    for (; stick[0].nb_stick - nb_stick <= param->matches; nb_stick -= 1);
    if (nb_stick == 0)
        nb_stick = 1;
    return (nb_stick);
}

void bot_strategy_one_line(stick_t *stick, game_t *param, int *tab, bot_t *b)
{
    int line = stick[0].line;
    int sticks = stick[0].nb_stick - 1;

    if (sticks > param->matches)
        remove_stick_game(tab, line, get_number_stick(stick, param));
    else if (sticks == 0) {
        sticks = 1;
        remove_stick_game(tab, line, sticks);
    } else
        remove_stick_game(tab, line, sticks);
    if (!b->count) {
        b->count = 1;
        b->line = line;
        b->stick = sticks;
    }
}

void classic_strategy(stick_t *stick, game_t *param, int *tab, bot_t *b)
{
    int line = 0;
    int sticks = 0;

    srand(time(0));
    line = rand() % stick[0].count;
    srand(time(0));
    sticks = rand() % param->matches;
    while (sticks > stick[line].nb_stick)
        sticks /= 2;
    if (sticks == 0)
        sticks = 1;
    remove_stick_game(tab, stick[line].line, sticks);
    if (!b->count) {
        b->count = 1;
        b->line = stick[line].line;
        b->stick = sticks;
    }
}