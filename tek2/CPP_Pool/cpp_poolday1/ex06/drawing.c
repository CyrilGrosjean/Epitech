/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** drawing
*/

#include "drawing.h"
#include "bitmap.h"

void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color)
{
    for (unsigned int y = 0; y < size; y += 1) {
        for (unsigned int x = 0; x < size; x += 1) {
            img[y + origin->y][x + origin->x] = color;
        }
    }
}

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;

    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;

    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}