/*
** EPITECH PROJECT, 2019
** open file
** File description:
** open files function
*/

#include "../include/my_popup.h"

int open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat st;
    int rd = 0;
    char *text;

    if (fd == -1) {
        write(2, "Can't open the file.\n", 22);
        return (84);
    }
    stat(file, &st);
    text = malloc(sizeof(char) * (st.st_size + 1));
    text[st.st_size] = '\0';
    rd = read(fd, text, st.st_size);
    if (rd == -1) {
        write(2, "Can't read the file.\n", 22);
        return (84);
    }
    rd = init(text);
    free(text);
    return (rd);
}