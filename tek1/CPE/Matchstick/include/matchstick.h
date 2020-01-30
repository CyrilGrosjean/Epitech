/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick prototypes of functions
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

typedef struct stick_s {

    int line;
    int nb_stick;
    int count;

} stick_t;

typedef struct bot_s {

    int line;
    int stick;
    int count;
    int index;
    int lose;

} bot_t;

typedef struct game_s {

    int lines;
    int matches;
    int max_sticks_line;

} game_t;

int my_put_nbr(int nb);
int check_line_error(game_t *param, int line, char *choice);
int check_error_match(game_t *param, int *tab, char *choice, int line);
void my_putstr(int output, char *str);
int my_getnbr(char const *str);
void display_board(int *tab, game_t *t);
int get_params(char *lines, char *matches);
int in_game(int *tab, game_t *params);
void remove_stick_player(int *tab, int line, int match);
void remove_stick_bot(int *tab, int line, int match);
int check_end(int *tab, game_t *params);
int *get_every_line(int line);

// BOT FUNCTIONS

bot_t bot_game(int *tab, game_t *param);
int bot_play(int *tab, game_t *param);
stick_t *set_array_stick(game_t *param, int *tab);
void bot_strategy_one_line(stick_t *stick, game_t *param, int *tab, bot_t *b);
void classic_strategy(stick_t *stick, game_t *param, int *tab, bot_t *b);
void remove_stick_game(int *tab, int line, int match);

#endif