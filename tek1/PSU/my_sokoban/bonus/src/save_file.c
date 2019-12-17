/*
** EPITECH PROJECT, 2019
** save file
** File description:
** save file when you edit the map
*/

#include "../include/my_popup.h"

void display_savefile(char *name)
{
    clear();
    if (LINES < 5 || COLS < 45)
        display_too_small();
    else {
        mvprintw(0, 0, "Name of the file:");
        mvprintw(0, 19, name);
        mvprintw(2, 0, "Maximum 20 characters.");
        mvprintw(3, 0, "Press 'ENTER' for save the filename.");
        mvprintw(4, 0, "If no name entered, save will be canceled.");
    }
    refresh();
}

char *get_key_save(int key, char *str)
{
    int len = my_strlen(str);

    if ((key >= '0' && key <= '9') || (key >= 'A' && key <= 'Z'))
        str[len] = key;
    if (key == '_' || (key >= 'a' && key <= 'z'))
        str[len] = key;
    if (key == 127 && my_strlen(str) > 0)
        str[len - 1] = '\0';
    return (str);
}

char *my_stradd(char *path, char *name)
{
    int len_path = my_strlen(path);
    int len_name = my_strlen(name);
    char *pathfile = malloc(sizeof(char) * (len_path + len_name + 1));
    int i = 0;

    for (i = 0; path[i]; i += 1)
        pathfile[i] = path[i];
    for (int j = 0; name[j]; j += 1) {
        pathfile[i] = name[j];
        i += 1;
    }
    pathfile[i] = '\0';
    return (pathfile);
}

int save_file(char *str, char *name)
{
    char path[9] = "../maps/";
    char *filepath = my_stradd(path, name);
    int fd = open(filepath, O_WRONLY | O_CREAT, S_IRWXU);

    if (fd == -1)
        return (84);
    write(fd, str, (my_strlen(str) - 1));
    close(fd);
    free(filepath);
    return (0);
}

int save_map(int save, char *str)
{
    char *name = malloc(sizeof(char) * (20 + 1));
    int key = 0;
    int loop = TRUE;

    for (int i = 0; i <= 20; i += 1)
        name[i] = '\0';
    if (!save || my_strlen(str) == 0)
        loop = FALSE;
    while (loop) {
        display_savefile(name);
        key = getch();
        if (key == 10)
            loop = FALSE;
        else
            name = get_key_save(key, name);
    }
    if (my_strlen(name) > 0)
        save_file(str, name);
    free(name);
    return (0);
}