/*
** EPITECH PROJECT, 2019
** make list
** File description:
** make int list for numbers
*/

#include "../include/pushswap.h"

int get_index_smallest(int *list_a, int size_a)
{
    int small = 0;
    int index = 0;

    if (size_a == 0)
        return (0);
    small = list_a[0];
    for (int i = 0; i < size_a; i += 1)
        if (list_a[i] < small) {
            small = list_a[i];
            index = i;
        }
    return (index);
}

int get_smallest_number(int *list_a, int size_a)
{
    int small = 0;

    if (size_a == 0)
        return (0);
    small = list_a[0];
    for (int i = 0; i < size_a; i += 1)
        if (list_a[i] < small)
            small = list_a[i];
    return (small);
}

int my_getnbr(char *str)
{
    long nb = 0;
    int k = 0;
    int minus = 0;

    if (str[0] == '-') {
        k = 1;
        minus = 1;
    }
    for (k = k; str[k]; k += 1) {
        nb += str[k] - '0';
        nb *= 10;
    }
    nb /= 10;
    if (minus)
        nb *= -1;
    return (nb);
}

int make_list(int ac, char **av)
{
    int *list_a = malloc(sizeof(int) * (ac));
    int *list_b = malloc(sizeof(int) * (ac));
    int index = 0;
    int k = 0;

    for (int i = 1; i < ac; i += 1) {
        for (k = 0; av[i][k] && av[i][k] >= '0' && av[i][k] <= '9'; k += 1);
        if ((av[i][k] && av[i][k] < '0') || (av[i][k] && av[i][k] > '9'))
            if (av[i][k] != '-') {
                free(list_a);
                return (84);
            }
        list_a[index] = my_getnbr(av[i]);
        index += 1;
    }
    if (ac == 2)
        return (my_putchar('\n'));
    my_sort_int_array(list_a, list_b, (ac - 1));
    free(list_a);
    free(list_b);
    return (0);
}