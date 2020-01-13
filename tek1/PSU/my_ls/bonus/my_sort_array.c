/*
** EPITECH PROJECT, 2020
** my sort array
** File description:
** functions to sort a str array
*/

#include "../include/ls.h"

int check_word(char *first, char *second, int index)
{
    int first_char = first[index];
    int sec_char = second[index];

    if (first_char >= 'A' && first_char <= 'Z')
        first_char += 32;
    if (sec_char >= 'A' && sec_char <= 'Z')
        sec_char += 32;
    if (first[index] == '\0' && second[index] == '\0')
        return (1);
    if (first_char > sec_char)
        return (0);
    else if (first_char < sec_char)
        return (1);
    else
        if (first[index] == second[index] + 32)
            return (0);
        else if (first[index] + 32 == second[index])
            return (1);
        else
            return (check_word(first, second, index + 1));
}

int check_sort_array(char **tab)
{
    for (int i = 1; tab[i] != NULL; i += 1)
        if (!check_word(tab[i - 1], tab[i], 0))
            return (0);
    return (1);
}

void sort_array(char **tab)
{
    char *temp;
    int sort = 0;

    for (int i = 1; tab[i] != NULL; i += 1) {
        sort = check_word(tab[i - 1], tab[i], 0);
        if (!sort) {
            temp = tab[i - 1];
            tab[i - 1] = tab[i];
            tab[i] = temp;
        }
    }
}

void my_sort_array(char **tab)
{
    int sort = 0;

    while (!sort) {
        sort = check_sort_array(tab);
        sort_array(tab);
    }
}