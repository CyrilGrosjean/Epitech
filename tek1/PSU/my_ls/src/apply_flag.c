/*
** EPITECH PROJECT, 2020
** apply flag
** File description:
** functions to apply flags on ls
*/

#include "../include/ls.h"

file_t *my_flags(flags_t *flag, file_t *files, int count, char *path)
{
    if (flag[4].applied)
        sort_time_array_struct(files, count);
    if (flag[3].applied)
        reverse_array_struct(files, count);
    if (flag[2].applied) {
        if (flag[0].applied)
            display_d(path);
        else {
            my_putstr(path);
            my_putchar('\n');
        }
        return (files);
    }
    if (flag[1].applied)
        return (files);
    else if (flag[0].applied)
        flag_l(files, count);
    return (files);
}

file_t *apply_flags_without_path(flags_t *flag, file_t *files)
{
    int count = count_files(".");

    files = get_dir(".", count);
    files = my_flags(flag, files, count, ".");
    for (int i = 0; i < count && flag[5].applied; i += 1)
        display_name(&files[i]);
    return (files);
}

void flags_dir(file_t *files, flags_t *flag, char **path, int i)
{
    int count = 0;

    count = count_files(path[i]);
    files = get_dir(path[i], count);
    files = my_flags(flag, files, count, path[i]);
    for (int i = 0; i < count && flag[5].applied; i += 1)
        display_name(&files[i]);
    free_files(files, count);
}

void flags_file(char **path, int i, flags_t *flag)
{
    int count = 1;
    file_t *file = malloc(sizeof(file_t) * 2);
    char *pathfile = get_path(path[i]);
    char *name = get_name(path[i]);

    file[1].file_name = NULL;
    if (name != NULL) {
        fill_struct(&file[0], pathfile, name);
        free(name);
    } else
        fill_struct(&file[0], pathfile, path[i]);
    file = my_flags(flag, file, count, pathfile);
    if (flag[5].applied)
        display_name(&file[0]);
    free(pathfile);
    free(file[0].file_name);
    free(file[0].access_rights);
    free(file[0].date);
    free(file[0].path);
    free(file);
}

file_t *apply_flags(flags_t *flag, char **path, file_t *files)
{
    struct stat st;

    if (path[0] == NULL) {
        files = apply_flags_without_path(flag, files);
        return (files);
    }
    for (int i = 0; path[i] != NULL; i += 1) {
        if (stat(path[i], &st) < 0) {
            write(2, "Error: No such file or directory.\n", 35);
            exit(84);
        }
        switch (st.st_mode & __S_IFMT) {
            case __S_IFDIR:
                flags_dir(files, flag, path, i);
                break;
            default:
                flags_file(path, i, flag);
                break;
        }
    }
    return (files);
}