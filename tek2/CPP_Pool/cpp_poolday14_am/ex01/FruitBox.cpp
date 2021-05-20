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
    _head = new FruitNode();
}

bool FruitBox::putFruit(Fruit *f)
{
    if (_size < _fruitNumber + 1) {
        return (false);
    }
    bool result = this->_head->push(f);
    if (result)
        _fruitNumber += 1;
    return (result);
}

Fruit *FruitBox::pickFruit(void)
{
    Fruit *fruit = nullptr;
    FruitNode *tmp;

    if (_fruitNumber == 0)
        return (nullptr);
    fruit = this->_head->pick();
    _fruitNumber -= 1;
    tmp = this->_head;
    this->_head = this->_head->getNext();
    delete (tmp);
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
}
