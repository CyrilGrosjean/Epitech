/*
** EPITECH PROJECT, 2021
** cpp_poolday1
** File description:
** bitmap_header
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = (uint16_t) (0x424D << 8) | (0x424D >> 8);
    header->size = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
    header->size += size * size * 4;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = 54;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->bpp = 32;
    header->compression = 0;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
    header->planes = 1;
    header->width = size;
    header->height = size;
    header->raw_data_size = size * size * 4;
}