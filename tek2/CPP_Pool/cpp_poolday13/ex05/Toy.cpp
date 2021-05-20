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

void Toy::speak(std::string statement, bool isEs)
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
        std::cout << type << ": " << _name << (isEs ? " senorita \"" : " \"") << statement
        << (isEs ? "\" senorita" : "\"") << std::endl;
        return;
    }
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(std::string statement)
{
    if (_type == BUZZ) {
        speak(statement, true);
        return (true);
    }
    return (false);
}

Toy &Toy::operator<<(std::string content)
{
    _picture.data = content;
    return (*this);
}

std::string Toy::Error::what(void)
{
    if (Error::t == Error::PICTURE) {
        
    }
}

Toy::~Toy()
{
}

std::ostream &operator<<(std::ostream &s, Toy &toy)
{
    s << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return (s);
}