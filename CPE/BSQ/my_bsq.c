/*
** EPITECH PROJECT, 2019
** my bsq
** File description:
** linear function for BSQ project
*/

#include "includes/bsq.h"
#include <sys/stat.h>

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat st;
    int rd = 0;
    char *str;

    if (fd == -1) {
        write(2, "Can't open file.\n", 18);
        return ("-1");
    }
    stat(file, &st);
    str = malloc(sizeof(char) * (st.st_size + 1));
    rd = read(fd, str, st.st_size);
    str[st.st_size] = '\0';
    if (rd == -1) {
        write(2, "Can't read the file.\n", 21);
        return ("-1");
    }
    close(fd);
    return (str);
}

int my_bsq(char *file)
{
    int error = 0;
    char *str = open_file(file);

    error = generate_square(str);
    free(str);
    if (error == 84)
        return (84);
    return (0);
}