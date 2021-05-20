/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** mem_ptr
*/

#include "mem_ptr.h"
#include <string.h>
#include <stdlib.h>

void add_str(const char *str1, const char *str2, char **res)
{
    int len = strlen(str1) + strlen(str2);

    *res = malloc(sizeof(char) * (len + 1));
    memset(*res, 0, len);
    strcat(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    int len = strlen(str_op->str1) + strlen(str_op->str2);

    str_op->res = malloc(sizeof(char) * (len + 1));
    memset(str_op->res, 0, len);
    strcat(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}