/*
** EPITECH PROJECT, 2019
** bsq.h
** File description:
** prototypes for functions in bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef struct dimensions_s {
    int width;
    int height;
} dimensions_t;

typedef struct square_s {
    int x_start;
    int y_start;
    int len;
} square_t;

int my_getnbr(char const *str);
int my_isnumb(char const c);
void my_putchar(char c);
int my_putstr(char const *str);
dimensions_t get_dimensions(char *str);
int check_square(char **tab, int i, square_t sqr, dimensions_t dim);
int check_mybsq(char **tab, square_t sqr, dimensions_t dim);
int generate_square(char *str);
int display_square(char **tab, square_t sqr, dimensions_t dim);
int my_bsq(char *file);
int check_line(char *str, square_t sqr);
char *open_file(char *file);

#endif