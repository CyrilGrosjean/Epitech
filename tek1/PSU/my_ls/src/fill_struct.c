/*
** EPITECH PROJECT, 2020
** fill stucture
** File description:
** functions to fill structure files_t
*/

#include "../include/ls.h"

void struct_stats(file_t *file)
{
    struct stat st;
    struct passwd *ps;
    struct group *gp;

    lstat(file->path, &st);
    gp = getgrgid(st.st_gid);
    ps = getpwuid(st.st_uid);
    file->access_rights = get_access_right(st);
    file->date = get_time(st);
    file->hardlinks = st.st_nlink;
    file->owner = ps->pw_name;
    file->owner_group = gp->gr_name;
    file->size = st.st_size;
    file->blocks = st.st_blocks;
    file->blksize = st.st_blksize;
}

void fill_struct(file_t *file, char *path, char *name)
{
    file->file_name = my_str_copy(name);
    file->path = make_path(path, name);
    struct_stats(file);
}