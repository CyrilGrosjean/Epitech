/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "bitmap.h"
#include "drawing.h"
#include "menger.h"

void initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; i++) {
        img[i] = buffer + i * size;
    }
}

void create_bitmap_from_buffer(size_t size, unsigned int *buffer, char *name)
{
    int fd = open(name, O_CREAT | O_TRUNC | O_WRONLY , 0644);

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int no_errors(int ac, char **av)
{
    if (ac != 4)
        return (0);
    if (atoi(av[2]) < 0 || atoi(av[2]) % 3 != 0)
        return (0);
    if (atoi(av[3]) < 0 || atoi(av[3]) > atoi(av[2]) / 3)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    size_t size = 0;
    unsigned int *buffer = NULL;
    unsigned int **img = NULL;
    co_t coords = {0, 0};

    if (!no_errors(ac, av)) {
        write(2, "menger_face file_name size level\n", 34);
        return (84);
    }
    size = (size_t)(atoi(av[2]));
    buffer = malloc(size * size * sizeof(*buffer));
    img = malloc(size * sizeof(*img));
    initialize_image(size, buffer, img);
    menger(atoi(av[2]) / 3, atoi(av[3]), coords, img);
    create_bitmap_from_buffer(size, buffer, av[1]);
    return (0);
}