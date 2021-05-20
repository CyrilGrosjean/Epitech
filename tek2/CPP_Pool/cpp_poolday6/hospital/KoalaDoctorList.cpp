/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor): koala(doctor)
{
    next = nullptr;
}

bool KoalaDoctorList::isEnd(void)
{
    if (next == nullptr) {
        return (true);
    }
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *object)
{
    KoalaDoctorList *tmp = this;

    if (getFromName(object->getContent()->getName()) != nullptr)
        return;
    for (; tmp->next != nullptr; tmp = tmp->next);
    tmp->next = object;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    for (; tmp != nullptr; tmp = tmp->next)
        if (tmp->koala != nullptr && tmp->koala->getName() == name)
            break;
    if (tmp != nullptr)
        return (tmp->koala);
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *elemToRemove)
{
    KoalaDoctorList *tmp = this;

    for (; tmp->next != elemToRemove && tmp->next != nullptr; tmp = tmp->next);
    if (tmp->next == elemToRemove) {
        tmp->next = elemToRemove->next;
    }
    return (this);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string nameToRemove)
{
    KoalaDoctorList *tmp = this;

    for (; tmp->next != nullptr; tmp = tmp->next) {
        if (tmp->next->koala != nullptr &&
        tmp->next->koala->getName() == nameToRemove) {
            tmp->next = tmp->next->next;
            return (this);
        }
    }
    return (this);
}

KoalaDoctor *KoalaDoctorList::getContent(void)
{
    return (this->koala);
}

KoalaDoctorList *KoalaDoctorList::getNext(void)
{
    return (this->next);
}

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
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

KoalaDoctorList::~KoalaDoctorList()
{
}
