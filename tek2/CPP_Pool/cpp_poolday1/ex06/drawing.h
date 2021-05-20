/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** drawing
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct point_s {
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size,
uint32_t color);
void write_bmp_header(int fd, size_t size);
void write_bmp_info_header(int fd, size_t size);

#endif /* !DRAWING_H_ */
