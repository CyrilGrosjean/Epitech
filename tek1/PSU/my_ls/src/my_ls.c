/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** my ls functions
*/

#include "../include/ls.h"

static flags_t flag[6] = {
    {'l', 0},
    {'R', 0},
    {'d', 0},
    {'r', 0},
    {'t', 0},
    {'N', 1},
};

int count_files(char *path)
{
    int count = 0;
    DIR *directory = NULL;
    struct dirent *read = NULL;

    directory = opendir(path);
    if (!directory) {
        write(2, "Error: No such file or directory.\n", 35);
        exit(84);
    }
    while ((read = readdir(directory)) != NULL)
        count += 1;
    closedir(directory);
    return (count);
}

file_t *get_dir(char *path, int count)
{
    DIR *dir = NULL;
    struct dirent *rd = NULL;
    file_t *files = malloc(sizeof(file_t) * (count + 1));
    int index = 0;

    if (!files)
        exit(84);
    files[count].file_name = NULL;
    dir = opendir(path);
    while ((rd = readdir(dir)) != NULL) {
        fill_struct(&files[index], path, rd->d_name);
        index += 1;
    }
    closedir(dir);
    return (files);
}

void analyze_flags(char *str)
{
    for (int i = 1; str[i]; i += 1)
        for (int j = 0; j < 5; j += 1) {
            if (str[i] == flag[j].flag)
                flag[j].applied = 1;
            if (flag[5].applied)
                flag[5].applied = get_check_flag(flag, j);
        }
}

char **analyze_arguments(int ac, char **av)
{
    char **paths = malloc(sizeof(char *) * ac);
    int index = 0;

    for (int i = 1; i < ac; i += 1) {
        if (av[i][0] == '-')
            analyze_flags(av[i]);
        else {
            paths[index] = av[i];
            index += 1;
        }
    }
    paths[index] = NULL;
    return (paths);
}

int my_ls(int ac, char **av)
{
    file_t *files = NULL;
    char **paths = NULL;
    int count = 0;

    if (ac == 1) {
        count = count_files(".");
        files = get_dir(".", count);
        for (int i = 0; i < count; i += 1)
            display_name(&files[i]);
        free_files(files, count);
    } else {
        paths = analyze_arguments(ac, av);
        files = apply_flags(flag, paths, files);
    }
    free_path(paths);
    return (0);
}