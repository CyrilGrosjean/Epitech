/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function for testing get next line
*/

#include "get_next_line.h"

char *get_next_line(int fd);

int main(void)
{
    int fd = open("tests/test_file.txt", O_RDONLY);

    if (fd == -1)
        return (84);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    return (0);
}