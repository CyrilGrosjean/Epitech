/*
** EPITECH PROJECT, 2019
** swap_elem
** File description:
** Swap two elements in an int *
*/

void swap_elem(int *array, int index1, int index2)
{
    int swap = 0;

    swap = array[index2];
    array[index2] = array[index1];
    array[index1] = swap;
}
