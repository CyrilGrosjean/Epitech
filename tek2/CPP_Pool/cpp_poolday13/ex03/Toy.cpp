/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string name, std::string file)
{
    _picture = Picture();
    _type = type;
    _name = name;
    _file = file;
    if (!file.empty())
        _picture.getPictureFromFile(_file);
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string &file)
{
    _file = file;
    return (_picture.getPictureFromFile(_file));
}

std::string Toy::getAscii(void)
{
    return (_picture.data);
}

Toy *Toy::operator=(Toy *other)
{
    _picture = other->_picture;
    _file = other->_file;
    _name = other->_name;
    _type = other->_type;
    return (this);
}

void Toy::speak(std::string statement)
{
    std::string type;

    switch (_type) {
        case BUZZ:
            type = "BUZZ";
            break;
        case WOODY:
            type = "WOODY";
            break;
        default:
            type = "";
            break;
    }
    if (!type.empty()) {
        std::cout << type << ": " << _name << " \"" << statement << "\"" << std::endl;
        return;
    }
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy::~Toy()
{
}
