/*
** EPITECH PROJECT, 2020
** bot
** File description:
** bot functions
*/

#include "../../include/matchstick.h"

bot_t *fill_bot_struct(bot_t *bot)
{
    for (int i = 0; i < 6; i += 1) {
        bot[i].line = -1;
        bot[i].count = 0;
        bot[i].stick = 0;
    }
    return (bot);
}

int *tab_copy_int(int *tab, int *tab_copy, game_t *param)
{
    for (int i = 0; i < param->lines; i += 1)
        tab_copy[i] = tab[i];
    return (tab_copy);
}

bot_t *check_bot_result(bot_t *moves, bot_t *best)
{
    for (int i = 0; moves[i].line != -1; i += 1) {
        if (best->line == moves[i].line && best->stick == moves[i].stick) {
            moves[i].count += 1;
            return (moves);
        }
    }
    moves[moves[0].index].line = best->line;
    moves[moves[0].index].count = 1;
    moves[moves[0].index].stick = best->stick;
    moves[moves[0].index].index += 1;
    return (moves);
}

bot_t get_best_move(bot_t *moves)
{
    bot_t win;

    win.count = 0;
    for (int i = 0; moves[i].line != -1; i += 1)
        if (moves[i].count > win.count) {
            win.count = moves[i].count;
            win.line = moves[i].line;
            win.stick = moves[i].stick;
        }
    return (win);
}

int bot_play(int *tab, game_t *param)
{
    bot_t *bot_moves = malloc(sizeof(bot_t) * (5 + 1));
    bot_t best;
    int *tab_copy = malloc(sizeof(int) * (param->lines));

    bot_moves[0].index = 0;
    tab_copy = tab_copy_int(tab, tab_copy, param);
    bot_moves = fill_bot_struct(bot_moves);
    for (int i = 0; i < 6; i += 1) {
        best = bot_game(tab_copy, param);
        while (best.lose == 2) {
            tab_copy = tab_copy_int(tab, tab_copy, param);
            best = bot_game(tab_copy, param);
        }
        bot_moves = check_bot_result(bot_moves, &best);
        tab_copy = tab_copy_int(tab, tab_copy, param);
    }
    best = get_best_move(bot_moves);
    remove_stick_bot(tab, best.line, best.stick);
    free(bot_moves);
    free(tab_copy);
    return (1);
}