/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *value): nurse(value)
{
    this->next = nullptr;
}

bool KoalaNurseList::isEnd(void)
{
    if (this->next == nullptr)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *object)
{
    KoalaNurseList *tmp = this;

    if (getFromID(object->getContent()->getID()) != nullptr)
        return;
    for (; tmp->next != nullptr; tmp = tmp->next);
    tmp->next = object;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this;

    for (; tmp != nullptr; tmp = tmp->next)
        if (tmp->nurse != nullptr && tmp->nurse->getID() == id)
            break;
    if (tmp != nullptr)
        return (tmp->nurse);
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *elemToRemove)
{
    KoalaNurseList *tmp = this;

    for (; tmp->next != elemToRemove && tmp->next != nullptr; tmp = tmp->next);
    if (tmp->next == elemToRemove) {
        tmp->next = elemToRemove->next;
    }
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *tmp = this;

    for (; tmp->next != nullptr; tmp = tmp->next) {
        if (tmp->next->nurse != nullptr &&
        tmp->next->nurse->getID() == id) {
            tmp->next = tmp->next->next;
            return (this);
        }
    }
    return (this);
}

KoalaNurse *KoalaNurseList::getContent(void)
{
    return (this->nurse);
}

KoalaNurseList *KoalaNurseList::getNext(void)
{
    return (this->next);
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    for (; tmp != nullptr; tmp = tmp->next) {
        if (tmp->nurse != nullptr)
            std::cout << tmp->nurse->getID();
        else
            std::cout << "[nullptr]";
        if (tmp->next != nullptr)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
    }
}

KoalaNurseList::~KoalaNurseList()
{
}
