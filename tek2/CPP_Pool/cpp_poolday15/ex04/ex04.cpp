/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex04
*/

#include "ex04.hpp"

template<>
bool Tester<int>::equal(int const a, int const b)
{
    return (::equal(a, b));
}

template<>
bool Tester<float>::equal(float const a, float const b)
{
    return (::equal(a, b));
}

template<>
bool Tester<double>::equal(double const a, double const b)
{
    return (::equal(a,b));
}

template<>
bool Tester<std::string>::equal(std::string const a, std::string const b)
{
    return (::equal(a, b));
}