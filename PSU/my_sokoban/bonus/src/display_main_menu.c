/*
** EPITECH PROJECT, 2019
** display main menu
** File description:
** Functions for main menu
*/

#include "../include/my_popup.h"

void display_menu(int select)
{
    char choice[3] = "->";
    char title[11] = "My Sokoban";
    char begin[5] = "Play";
    char edit[5] = "Edit";
    char quit[5] = "Exit";

    curs_set(0);
    clear();
    if (LINES < 22 || COLS < ((COLS / 2) + 10))
        display_too_small();
    else {
        mvprintw((LINES / 2) + (select * 2), (COLS / 2) - 6, choice);
        mvprintw((LINES / 2) - 10, (COLS / 2) - 5, title);
        mvprintw((LINES / 2), (COLS / 2) - 2, begin);
        mvprintw((LINES / 2) + 2, (COLS / 2) - 2, edit);
        mvprintw((LINES / 2) + 4, (COLS / 2) - 2, quit);
    }
    refresh();
}

int get_key_main_menu(int key, int select)
{
    if (key == 65) {
            select -= 1;
            if (select < 0)
                select = 0;
        }
        if (key == 66) {
            select += 1;
            if (select > 2)
                select = 2;
        }
    return (select);
}