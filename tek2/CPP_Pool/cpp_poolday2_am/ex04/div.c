/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** div
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    float result = 0.0;

    if (b == 0)
        return (0);
    result = (float) a / (float) b;
    return (result);
}

void exec_div(division_t *operation)
{
    integer_op_t *integer_op;
    decimale_op_t *decimale_op;

    if (operation->div_type == INTEGER) {
        integer_op = operation->div_op;
        integer_op->res = integer_div(integer_op->a, integer_op->b);
    } else {
        decimale_op = operation->div_op;
        decimale_op->res = decimale_div(decimale_op->a, decimale_op->b);
    }
}