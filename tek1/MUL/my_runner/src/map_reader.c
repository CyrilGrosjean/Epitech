/*
** EPITECH PROJECT, 2019
** map reader
** File description:
** functions for map reader
*/

#include "../include/runner.h"

int count_objects(char *map)
{
    int nb = 0;

    for (int i = 0; map[i]; i += 1)
        if (map[i] == '1')
            nb += 1;
    return (nb);
}

int read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    int rd = 0;
    struct stat st;
    char *map;
    int val = 0;

    if (fd == -1)
        return (putstr_error("Can't open file.\n"));
    stat(file, &st);
    map = malloc(sizeof(char) * (st.st_size + 1));
    map[st.st_size] = '\0';
    rd = read(fd, map, st.st_size);
    if (fd == -1 || rd == -1 || count_lines(map) != 8)
        return (putstr_error("Can't read map or invalid map.\n"));
    val = initialisation(map);
    free(map);
    return (val);
}