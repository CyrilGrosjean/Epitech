/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** PacmanException
*/

#include "PacmanException.hpp"

PacmanException::PacmanException(std::string what)
{
    this->_what = what;
}

const char *PacmanException::what(void) const noexcept
{
    return (this->_what.c_str());
}

PacmanException::~PacmanException()
{
}

ObjectError::ObjectError(std::string what): PacmanException(what)
{
}

ObjectError::~ObjectError()
{
}
