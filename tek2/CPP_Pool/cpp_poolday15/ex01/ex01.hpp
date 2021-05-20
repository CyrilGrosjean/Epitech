/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <string.h>
#include <stdio.h>

template <typename T>
int compare(const T &s1, const T &s2)
{
    if (s1 > s2)
        return (1);
    if (s1 == s2)
        return (0);
    return (-1);
}

template <>
int compare<const char *>(const char * const &s1, const char * const &s2)
{
    int result = strcmp(s1, s2);

    if (result < 0)
        return (-1);
    if (result > 0)
        return (1);
    return (0);
}

#endif /* !EX01_HPP_ */
