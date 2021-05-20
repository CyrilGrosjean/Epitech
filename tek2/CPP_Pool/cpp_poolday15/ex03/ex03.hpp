/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(T *array, void (func)(const T &elem), size_t size)
{
    for (size_t i = 0; i < size; i += 1) {
        (*func)(array[i]);
    }
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif /* !EX03_HPP_ */
