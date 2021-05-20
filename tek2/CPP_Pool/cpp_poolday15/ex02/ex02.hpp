/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a == b)
        return (a);
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    if (a == b)
        return (a);
    if (a < b)
        return (a);
    return (b);
}

int nonTemplateMin(int *tab, size_t size)
{
    int smaller = tab[0];
    int tmp;

    for (size_t i = 1; i < size; i += 1) {
        tmp = ::min(tab[i - 1], tab[i]);
        if (tmp < smaller)
            smaller = tmp;
    }
    return (smaller);
}

template<typename T>
T templateMin(T *tab, size_t size)
{
    T smaller = tab[0];
    T tmp;

    for (size_t i = 1; i < size; i += 1) {
        tmp = ::min<>(tab[i - 1], tab[i]);
        if (tmp < smaller)
            smaller = tmp;
    }
    return (smaller);
}

#endif /* !EX02_HPP_ */
