/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action): _koalaAction(action)
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &other)
{
    this->_koalaAction = other._koalaAction;
    this->_actions = other._actions;
    this->_keys = other._keys;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &other)
{
    this->_koalaAction = other._koalaAction;
    this->_actions = other._actions;
    this->_keys = other._keys;
    return (*this);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    if (command && action) {
        this->_actions.push_back(action);
        this->_keys.push_back(command);
    }
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    unsigned int index = 0;

    for (; index < this->_keys.size() && this->_keys[index] != command; index += 1);
    if (index == this->_keys.size())
        return;
    this->_keys.erase(this->_keys.begin() + index);
    this->_actions.erase(this->_actions.begin() + index);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    unsigned int index = 0;

    for (; index < this->_keys.size() && this->_keys[index] != command; index += 1);
    if (index == this->_keys.size())
        return;
    methodPointer_t func = this->_actions[index];

    (_koalaAction.*func)(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    this->_koalaAction = action;
}

DomesticKoala::~DomesticKoala()
{
}
