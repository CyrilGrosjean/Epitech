/*
** EPITECH PROJECT, 2020
** get stats
** File description:
** functions to get some stats
*/

#include "../include/ls.h"

char *get_access_right(struct stat st)
{
    char *rights = malloc(sizeof(char) * (10 + 1));

    if (!rights)
        exit(84);
    rights[10] = '\0';
    rights[0] = (S_ISDIR(st.st_mode)) ? 'd' : '-';
    rights[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
    rights[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
    rights[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
    rights[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
    rights[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
    rights[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
    rights[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
    rights[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
    rights[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
    return (rights);
}

char *get_time(struct stat st)
{
    char *time = malloc(sizeof(char) * (12 + 1));
    char *str = ctime(&st.st_mtime);
    int index = 0;

    if (!time)
        exit(84);
    time[12] = '\0';
    for (int i = 4; i < 16; i += 1) {
        if (i == 7)
            i += 1;
        time[index] = str[i];
        index += 1;
    }
    time[index] = '\0';
    return (time);
}

int get_check_flag(flags_t *flag, int index)
{
    if (flag[index].applied && flag[index].flag != flag[4].flag)
        if (flag[index].flag != flag[3].flag)
            return (0);
        else
            return (1);
    else
        return (1);
}