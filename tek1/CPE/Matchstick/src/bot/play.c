/*
** EPITECH PROJECT, 2020
** bot play
** File description:
** bot function play
*/

#include "../../include/matchstick.h"

void remove_stick_game(int *tab, int line, int match)
{
    tab[line - 1] -= match;
}

int bot_1_plays(int *tab, game_t *param, bot_t *b)
{
    stick_t *stick = set_array_stick(param, tab);

    if (stick[0].count == 1)
        bot_strategy_one_line(stick, param, tab, b);
    else
        classic_strategy(stick, param, tab, b);
    free(stick);
    return (2);
}

int bot_2_plays(int *tab, game_t *param)
{
    int line = 0;
    int sticks = 0;
    stick_t *stick = set_array_stick(param, tab);

    srand(time(0));
    line = rand() % stick[0].count;
    srand(time(0));
    sticks = rand() % param->matches;
    while (sticks > stick[line].nb_stick)
        sticks /= 2;
    if (sticks == 0)
        sticks = 1;
    remove_stick_game(tab, stick[line].line, sticks);
    free(stick);
    return (1);
}

bot_t bot_game(int *tab, game_t *param)
{
    bot_t bot_1;
    int lose = 1;
    stick_t *stick = set_array_stick(param, tab);

    bot_1.lose = 0;
    if (stick[0].count == 1 && stick[0].nb_stick == 1)
        bot_1.lose = 1;
    free(stick);
    bot_1.count = 0;
    while (1) {
        lose = bot_1_plays(tab, param, &bot_1);
        if (check_end(tab, param))
            break;
        lose = bot_2_plays(tab, param);
        if (check_end(tab, param))
            break;
    }
    if (bot_1.lose != 1)
        bot_1.lose = lose;
    return (bot_1);
}