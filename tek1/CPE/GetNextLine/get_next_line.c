/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** Functions for get_next_line
*/

#include "get_next_line.h"

int make_line(int index, char *line, char *my_line)
{
    for (int i = 0; i < READ_SIZE; i += 1) {
        if (line[i] == '\n' || (line[i] == '\0' && index != 0)) {
            my_line[index] = '\0';
            return (-1);
        } else if (line[i] == '\0' && index == 0) {
            free(my_line);
            return (-2);
        } else {
            my_line[index] = line[i];
            index += 1;
        }
    }
    return (index);
}

char *get_line(char *line, int fd)
{
    int index = 0;
    int rd = 0;
    char *my_line = malloc(sizeof(char) * (32000 + 1));

    if (!my_line)
        return (NULL);
    while (rd != -1) {
        for (int i = 0; i <= READ_SIZE; i += 1)
            line[i] = '\0';
        rd = read(fd, line, READ_SIZE);
        if (rd == -1) {
            free(my_line);
            return (NULL);
        }
        index = make_line(index, line, my_line);
        if (index == -2)
            return (NULL);
        if (index == -1)
            return (my_line);
    }
}

char *get_next_line(int fd)
{
    char *line = malloc(sizeof(char) * (READ_SIZE + 1));
    char *str = NULL;

    if (fd == -1 || !line)
        return (NULL);
    for (int i = 0; i <= READ_SIZE; i += 1)
        line[i] = '\0';
    str = get_line(line, fd);
    free(line);
    return (str);
}