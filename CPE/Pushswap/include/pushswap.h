/*
** EPITECH PROJECT, 2019
** pushswap include
** File description:
** Prototypes for the pushswap functions
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int make_list(int ac, char **av);
int my_strlen(char const *str);
int get_smallest_number(int *list_a, int size_a);
void rotate_left(int *array, int size);
void rotate_right(int *array, int size);
void swap_elem(int *array, int index1, int index2);
int my_putchar(char c);
int my_putstr(char const *str);
int my_sort_int_array(int *list_a, int *list_b, int size_a);
void switch_to_list_a(int *list_a, int *list_b, int size_a, int size_b);
void switch_to_list_b(int *list_a, int *list_b, int size_a, int size_b);
int get_index_smallest(int *list_a, int size_a);

#endif
