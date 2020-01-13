/*
** EPITECH PROJECT, 2020
** get path and file name
** File description:
** functions to get path and name
*/

#include "../include/ls.h"

int count_slash(char *path)
{
    int nb = 0;

    for (int i = 0; path[i]; i += 1)
        if (path[i] == '/')
            nb += 1;
    return (nb);
}

char *get_path(char *pathfile)
{
    char *str = malloc(sizeof(pathfile));
    int index = 0;
    int slash = count_slash(pathfile);

    if (slash == 0) {
        str[0] = '.';
        str[1] = '\0';
        return (str);
    }
    for (index = 0; pathfile[index]; index += 1) {
        if (slash == 0)
            break;
        if (pathfile[index] == '/')
            slash -= 1;
        str[index] = pathfile[index];
    }
    str[index - 1] = '\0';
    return (str);
}

char *get_name(char *pathfile)
{
    char *str = malloc(sizeof(char) * (my_strlen(pathfile) + 1));
    int index = 0;
    int slash = count_slash(pathfile);

    if (slash == 0) {
        free(str);
        return (NULL);
    }
    for (int i = 0; pathfile[i]; i += 1) {
        if (slash == 0) {
            str[index] = pathfile[i];
            index += 1;
        }
        if (pathfile[i] == '/')
            slash -= 1;
    }
    str[index] = '\0';
    return (str);
}