/*
** EPITECH PROJECT, 2021
** cpp_poolday17
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(std::string key): _key(key), _index(0)
{
}

void OneTime::encryptChar(char plainChar)
{
    char keyChar = this->_key.at(this->_index);
    int miniKey = 'A';
    int mini = 'A';

    if (isalpha(plainChar)) {
        if (plainChar >= 'a')
            mini = 'a';
        if (keyChar >= 'a')
            miniKey = 'a';
        plainChar -= mini;
        keyChar -= miniKey;
        plainChar += keyChar;
        plainChar %= 26;
        plainChar += mini;
    }
    this->_index = (this->_index + 1) % this->_key.size();
    std::cout << plainChar;
}

void OneTime::decryptChar(char cipherChar)
{
    char keyChar = this->_key.at(this->_index);
    int miniKey = 'A';
    int mini = 'Z';

    if (isalpha(cipherChar)) {
        if (cipherChar >= 'a')
            mini = 'z';
        if (keyChar >= 'a')
            miniKey = 'a';
        cipherChar -= mini;
        keyChar -= miniKey;
        cipherChar -= keyChar;
        cipherChar = cipherChar % 26;
        cipherChar += mini;
    }
    this->_index = (this->_index + 1) % this->_key.size();
    std::cout << cipherChar;
}

void OneTime::reset(void)
{
    this->_index = 0;
}

OneTime::~OneTime()
{
}
