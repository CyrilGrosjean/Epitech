/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** main function for my_printf
*/

#include "include/my.h"

static flag_t flags[13] = {
    {"s", my_putstr},
    {"c", my_putchar},
    {"d", my_put_nbr},
    {"i", my_put_nbr},
    {"ld", my_put_long},
    {"hd", my_put_short},
    {"x", my_put_hexa_lower},
    {"X", my_put_hexa_upper},
    {"S", my_put_nonprintable},
    {"b", my_put_binary},
    {"o", my_put_octal},
    {"u", my_put_nbr},
    {"p", display_pointer}
};

int is_flag(char *str, int i)
{
    if (str[i] == '%')
        i += 1;
    else
        return (0);
    while (str[i] == ' ' && str[i] == '%')
        i += 1;
    for (int k = 0; k < 13; k += 1) {
        if (str[i] == flags[k].c[0])
            return (1);
    }
    return (0);
}

int set_flag(char *str, int i, void *val)
{
    i += 1;
    while (str[i] == ' ')
        i += 1;
    for (int k = 0; k < 13; k += 1) {
        if (str[i] == flags[k].c[0]) {
            flags[k].pt(val);
            return (i);
        }
    }
    return (i);
}

int set_doublepercent(char *str, int i)
{
    int a = i;

    if (str[a] == '%')
        a += 1;
    else
        return (i);
    while (str[a] == ' ')
        a += 1;
    if (str[a] == '%') {
        my_putchar('%');
        i = a + 1;
    }
    return (i);
}

int my_printf(char *str, ...)
{
    va_list parameters;
    void *val;

    va_start(parameters, str);
    for (int i = 0; i < my_strlen(str); i += 1) {
        i = set_doublepercent(str, i);
        if (is_flag(str, i)) {
            val = va_arg(parameters, void *);
            i = set_flag(str, i, val);
        } else
            my_putchar(str[i]);
    }
    va_end(parameters);
    return (0);
}