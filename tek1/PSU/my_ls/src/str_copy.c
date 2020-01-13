/*
** EPITECH PROJECT, 2020
** str copy
** File description:
** function for copy a str
*/

#include "../include/ls.h"

char *make_path(char *src, char *name)
{
    int len_src = my_strlen(src);
    int len_name = my_strlen(name);
    char *str = malloc(sizeof(char) * (len_src + len_name + 2));
    int index = 0;

    for (index = 0; src[index]; index += 1)
        str[index] = src[index];
    str[index] = '/';
    index += 1;
    for (int i = 0; name[i]; i += 1) {
        str[index] = name[i];
        index += 1;
    }
    str[index] = '\0';
    return (str);
}

char *my_str_copy(char *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));
    int index = 0;

    if (!str)
        exit(84);
    str[len] = '\0';
    for (index = 0; src[index]; index += 1)
        str[index] = src[index];
    str[index] = '\0';
    return (str);
}