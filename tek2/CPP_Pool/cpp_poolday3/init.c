/*
** EPITECH PROJECT, 2021
** cpp_poolday3
** File description:
** init_string
*/

#include "string.h"

void define_number_ret_functions(string_t *this)
{
    this->size = size;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
    this->empty = empty;
    this->find_s = find_s;
    this->find_c = find_c;
    this->to_int = to_int;
}

void define_void_ret_functions(string_t *this)
{
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_s = append_s;
    this->append_c = append_c;
    this->insert_c = insert_c;
    this->insert_s = insert_s;
    this->clear = clear;
    this->print = print;
    this->join_c = join_c;
    this->join_s = join_s;
}

void define_other_ret_functions(string_t *this)
{
    this->at = at;
    this->c_str = c_str;
    this->split_c = split_c;
    this->split_s = split_s;
}

void string_init(string_t *this, const char *s)
{
    this->str = (char *) calloc(strlen(s) + 1, sizeof(char));
    strcpy(this->str, s);
    define_number_ret_functions(this);
    define_void_ret_functions(this);
    define_other_ret_functions(this);
}

void string_destroy(string_t *this)
{
    free(this->str);
}