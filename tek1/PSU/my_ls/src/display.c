/*
** EPITECH PROJECT, 2020
** display
** File description:
** display function
*/

#include "../include/ls.h"

void display_name(file_t *file)
{
    if (file->file_name[0] != '.') {
        my_putstr(file->file_name);
        my_putstr("\n");
    }
}

void display_l(file_t *file)
{
    my_putstr(file->access_rights);
    my_putstr(" ");
    my_put_nbr(file->hardlinks);
    my_putstr(" ");
    my_putstr(file->owner);
    my_putstr(" ");
    my_putstr(file->owner_group);
    my_putstr(" ");
    my_put_nbr(file->size);
    my_putstr(" ");
    my_putstr(file->date);
    my_putstr(" ");
    display_name(file);
}

void display_d(char *path)
{
    file_t file;
    char *pathfile = get_path(path);
    char *name = get_name(path);
    int len = 0;

    if (name != NULL) {
        fill_struct(&file, path, name);
        free(name);
    } else
        fill_struct(&file, pathfile, path);
    len = my_strlen(file.file_name);
    display_l(&file);
    if (file.file_name[len - 1] == '/' && file.file_name[len - 2] == '.') {
        my_putstr(file.file_name);
        my_putstr("\n");
    } else if (file.file_name[len - 1] == '.') {
        my_putstr(file.file_name);
        my_putstr("\n");
    }
    free(pathfile);
}