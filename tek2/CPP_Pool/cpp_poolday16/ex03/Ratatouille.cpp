/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    this->_stream.str("");
    this->_stream << other._stream.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other)
{
    this->_stream.str("");
    this->_stream << other._stream.str();
    return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char vegi)
{
    this->_stream << vegi;
    return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int cond)
{
    this->_stream << cond;
    return (*this);
}

Ratatouille &Ratatouille::addSpice(double spice)
{
    this->_stream << spice;
    return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string &sauce)
{
    this->_stream << sauce;
    return (*this);
}

std::string Ratatouille::kooc(void)
{
    return (this->_stream.str());
}

Ratatouille::~Ratatouille()
{
}
