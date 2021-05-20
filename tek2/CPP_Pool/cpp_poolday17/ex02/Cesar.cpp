/*
** EPITECH PROJECT, 2021
** cpp_poolday17
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar(): _decal(3)
{
}

void Cesar::encryptChar(char plainChar)
{
    int mini = 'A';

    if (isalpha(plainChar)) {
        if (plainChar >= 'a') {
            mini = 'a';
        }
        plainChar -= mini;
        plainChar += this->_decal;
        plainChar %= 26;
        plainChar += mini;
    }
    this->_decal += 1;
    std::cout << plainChar;
}

void Cesar::decryptChar(char plainChar)
{
    int mini = 'Z';

    if (isalpha(plainChar)) {
        if (plainChar >= 'a') {
            mini = 'z';
        }
        plainChar -= mini;
        plainChar -= this->_decal;
        plainChar %= 26;
        plainChar += mini;
    }
    this->_decal += 1;
    std::cout << plainChar;
}

void Cesar::reset(void)
{
    this->_decal = 3;
}

Cesar::~Cesar()
{
}
