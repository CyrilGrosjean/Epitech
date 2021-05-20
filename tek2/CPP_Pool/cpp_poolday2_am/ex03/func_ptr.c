/*
** EPITECH PROJECT, 2021
** cpp_poolday2_am
** File description:
** func_ptr
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int length = strlen(str);

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int length = strlen(str);
    const char offset = 'a' - 'A';
    char *strtoup = malloc(sizeof(char) * (length + 1));

    strtoup[length] = '\0';
    for (int i = 0; i < length; i += 1)
        strtoup[i] = (str[i] >= 'a' && str[i] <= 'z') ?
        str[i] - offset : str[i];
    printf("%s\n", strtoup);
    free(strtoup);
}

void print_42(__attribute__((unused)) const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    ptract_t act = {{
        &print_normal, &print_reverse, &print_upper, &print_42
    }};

    act.action[action](str);
}