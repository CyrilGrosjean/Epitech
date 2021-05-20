/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** func_ptr
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include "func_ptr_enum.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_action(action_t action, const char *str);

typedef void (*ptr)(const char *);

typedef struct ptract_s {

    ptr action[4];

} ptract_t;

#endif /* !FUNC_PTR_H_ */
