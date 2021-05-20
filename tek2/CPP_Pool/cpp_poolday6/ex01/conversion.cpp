/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** conversion
*/

#include "conversion.hpp"

float convert_fahrenheit(float value)
{
    float result = (value * 9 / 5) + 32;

    return (result);
}

float convert_celsius(float value)
{
    float result = (value - 32) * 5 / 9;

    return (result);
}

void display(std::string type, float result)
{
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) <<
    result << std::setw(16) << std::fixed << type << std::endl;
}

void convertion(std::string type, float value)
{
    float result;

    if (type == "Celsius") {
        result = convert_fahrenheit(value);
        display("Fahrenheit", result);
    } else if (type == "Fahrenheit") {
        result = convert_celsius(value);
        display("Celsius", result);
    }
}