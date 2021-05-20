/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** add_mul
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int firstValue = *first;
    int secondValue = *second;

    *first = firstValue + secondValue;
    *second = firstValue * secondValue;
}