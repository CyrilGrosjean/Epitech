/*
** EPITECH PROJECT, 2020
** free
** File description:
** functions to free
*/

#include "../include/ls.h"

void free_files(file_t *files, int count)
{
    for (int i = 0; i < count; i += 1) {
        free(files[i].file_name);
        free(files[i].access_rights);
        free(files[i].date);
        free(files[i].path);
    }
    free(files);
}

void free_path(char **path)
{
    if (path == NULL)
        return;
    free(path);
}