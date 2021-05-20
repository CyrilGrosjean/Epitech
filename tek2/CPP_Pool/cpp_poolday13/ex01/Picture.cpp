/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream f(file);
    char content;
    std::ostringstream stream;

    if (!f.is_open()) {
        data = "ERROR";
        return (false);
    }
    content = f.get();
    for (; f.good(); content = f.get()) {
        stream << content;
    }
    data = stream.str();
    f.close();
    return (true);
}

Picture &Picture::operator=(const Picture &other)
{
    this->data = other.data;
    return (*this);
}

Picture::~Picture()
{
}
