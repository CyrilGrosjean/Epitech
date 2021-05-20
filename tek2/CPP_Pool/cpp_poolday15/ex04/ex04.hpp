/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex04
*/

#ifndef EX04_HPP_
#define EX04_HPP_

#include <iostream>

template<typename T>
bool equal(T a, T b)
{
    if (a == b)
        return (true);
    return (false);
}

template<typename T>
class Tester {
    public:
        bool equal(T a, T b);
};

#endif /* !EX04_HPP_ */
