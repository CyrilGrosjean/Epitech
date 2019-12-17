/*
** EPITECH PROJECT, 2019
** my_popup h
** File description:
** prototypes of functions
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_POPUP_H_
#define MY_POPUP_H_

// 0 VOID
// 1 WALL
// 2 OBJECTIVE
// 3 BOX
// 4 PLAYER

typedef struct object_s {
    int boxes;
    int objectives;
    int player;
} object_t;

typedef struct player_s {
    int x;
    int y;
} player_t;

int my_popup(char *str);
int my_strlen(char const *str);
int open_file(char *file);
int init(char *text);
int render_console(char **tab, int **tab_int, player_t *player);
int count_lines(char *str);
int check_error(char **tab, int **tab_int, player_t *player);
int get_int(char c);
char get_char(int i);
char **move_right(char **tab, int **tab_int, player_t *player);
char **move_down(char **tab, int **tab_int, player_t *player);
char **move_left(char **tab, int **tab_int, player_t *player);
char **move_up(char **tab, int **tab_int, player_t *player);
int display_help(void);
void my_putchar(char c);
int my_putstr(char const *str);
int test_win(char **tab, int **tab_int);
int test_lose(char **tab, int **tab_int);
void display_too_small(void);
int quit(void);
int render_window_game(char **tab, int **tab_int, player_t *player);
void display_map(char **tab);
char **reset(char **tab, int **int_tab, player_t *player);
char **get_key(int key, char **tab, int **tab_int, player_t *player);
int render_window_main_menu(void);
int get_key_main_menu(int key, int select);
void display_menu(int select);
object_t init_object(void);
void display_window_editor(char *str);
char *check_key_editor(int key, char *str, object_t *object);
int render_window_edit(void);
char *my_int_to_str(int nb);
char *my_revstr(char *str);
int save_map(int save, char *str);
char *define_str(char *str);

#endif