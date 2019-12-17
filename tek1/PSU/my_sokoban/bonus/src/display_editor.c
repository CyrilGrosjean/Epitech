/*
** EPITECH PROJECT, 2019
** display editor
** File description:
** functions to display map editor
*/

#include "../include/my_popup.h"

object_t init_object(void)
{
    object_t object;

    object.boxes = 0;
    object.objectives = 0;
    object.player = 0;
    return (object);
}

char *set_str(char *str, char c, object_t *object)
{
    int len = my_strlen(str);

    if (len < 25001) {
        if (c == '\0' && len > 1) {
            if (str[len - 2] == 'X')
                object->boxes -= 1;
            if (str[len - 2] == 'O')
                object->objectives -= 1;
            if (str[len - 2] == 'P')
                object->player -= 1;
            str[len - 1] = '\0';
            str[len - 2] = '|';
        } else if (c != '\0') {
            str[len - 1] = c;
            str[len] = '|';
        }
    }
    return (str);
}

char *check_key_editor(int key, char *str, object_t *object)
{
    if (key == 'x') {
        str = set_str(str, 'X', object);
        object->boxes += 1;
    }
    if (key == 'p') {
        str = set_str(str, 'P', object);
        object->player += 1;
    }
    if (key == 'o') {
        str = set_str(str, 'O', object);
        object->objectives += 1;
    }
    if (key == '#' || key == '\n' || key == ' ')
        str = set_str(str, key, object);
    if (key == 127)
        str = set_str(str, '\0', object);
    return (str);
}

char *define_str(char *str)
{
    for (int i = 0; i < 2502; i += 1) {
        str[i] = '\0';
    }
    str[0] = '|';
    return (str);
}

void display_window_editor(char *str)
{
    char *len = my_int_to_str(2500 - (my_strlen(str) - 1));

    curs_set(0);
    clear();
    if (LINES < 55 || COLS < 100)
        display_too_small();
    else {
        mvprintw(0, 0, str);
        mvprintw(52, 0, "Characters left:");
        mvprintw(52, 17, len);
        mvprintw(52, 40, "INSTRUCTIONS:");
        mvprintw(53, 40, "'#' for walls ; SPACE for void ; \
ENTER for line return");
        mvprintw(54, 0, "Use 's' for save the map and close.");
        mvprintw(54, 40, "'P' for player ; 'X' for boxes ; 'O' for \
objectives");
        mvprintw(55, 0, "Use 'c' for cancel editing and close.");
    }
    free(len);
    refresh();
}