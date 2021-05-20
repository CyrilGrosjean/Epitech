/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _size = size;
    _fruitNumber = 0;
    _head = NULL;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *n = new FruitNode;
    FruitNode *tmp;

    if (this->_size < this->_fruitNumber + 1 || f == nullptr) {
        delete n;
        return (false);
    }
    n->fruit = f;
    n->next = nullptr;
    if (this->_head == NULL) {
        this->_head = new FruitNode;
        this->_head->fruit = f;
        this->_head->next = NULL;
        this->_fruitNumber += 1;
        delete n;
        return (true);
    }
    tmp = this->_head;
    for (; tmp && tmp->next != NULL && tmp->fruit != f; tmp = tmp->next);
    if (tmp->fruit == f) {
        delete n;
        return (false);
    }
    tmp->next = n;
    this->_fruitNumber += 1;
    return (true);
}

Fruit *FruitBox::pickFruit(void)
{
    FruitNode *tmp = this->_head;
    Fruit *fruit;

    if (this->_fruitNumber <= 0 || this->_head == NULL)
        return (nullptr);
    fruit = tmp->fruit;
    for (; tmp->next; tmp = tmp->next);
    this->_fruitNumber -= 1;
    return (fruit);
}

FruitNode *FruitBox::head(void) const
{
    if (_fruitNumber == 0)
        return (nullptr);
    return (this->_head);
}

FruitBox::~FruitBox()
{
    if (this->_head)
        delete this->_head;
}
