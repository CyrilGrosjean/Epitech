/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** main
*/

#include "conversion.hpp"

int main(void)
{
    std::string line;
    std::stringstream buffer;
    std::string text;
    float value;

    std::getline(std::cin, line);
    buffer << line;
    buffer >> value;
    buffer >> text;
    convertion(text, value);
    return (0);
}