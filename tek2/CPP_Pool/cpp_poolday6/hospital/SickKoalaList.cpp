/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient): koala(patient)
{
    next = nullptr;
}

bool SickKoalaList::isEnd(void)
{
    if (next == nullptr) {
        return (true);
    }
    return (false);
}

void SickKoalaList::append(SickKoalaList *object)
{
    SickKoalaList *tmp = this;

    if (getFromName(object->getContent()->getName()) != nullptr)
        return;
    for (; tmp->next != nullptr; tmp = tmp->next);
    tmp->next = object;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this;

    for (; tmp != nullptr; tmp = tmp->next)
        if (tmp->koala != nullptr && tmp->koala->getName() == name)
            break;
    if (tmp != nullptr)
        return (tmp->koala);
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *elemToRemove)
{
    SickKoalaList *tmp = this;

    for (; tmp->next != elemToRemove && tmp->next != nullptr; tmp = tmp->next);
    if (tmp->next == elemToRemove) {
        tmp->next = elemToRemove->next;
    }
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string nameToRemove)
{
    SickKoalaList *tmp = this;

    for (; tmp->next != nullptr; tmp = tmp->next) {
        if (tmp->next->koala != nullptr &&
        tmp->next->koala->getName() == nameToRemove) {
            tmp->next = tmp->next->next;
            return (this);
        }
    }
    return (this);
}

SickKoala *SickKoalaList::getContent(void)
{
    return (this->koala);
}

SickKoalaList *SickKoalaList::getNext(void)
{
    return (this->next);
}

void SickKoalaList::dump(void)
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    for (; tmp != nullptr; tmp = tmp->next) {
        if (tmp->koala != nullptr)
            std::cout << tmp->koala->getName();
        else
            std::cout << "[nullptr]";
        if (tmp->next != nullptr)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
    }
}

SickKoalaList::~SickKoalaList(void)
{
}
