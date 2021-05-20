/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** FruitNode
*/

#include "FruitNode.hpp"

FruitNode::FruitNode()
{
    this->_fruit = nullptr;
    this->_next = nullptr;
}

bool FruitNode::push(Fruit *fruit)
{
    FruitNode *tmp = this;
    FruitNode *n = new FruitNode();

    if (!tmp)
        return (false);
    n->_fruit = fruit;
    n->_next = nullptr;
    for (; tmp->_next != nullptr || tmp->_fruit == fruit; tmp = tmp->_next);
    if (tmp->_fruit == fruit)
        return (false);
    tmp->_next = n;
    return (true);
}

Fruit *FruitNode::pick(void)
{
    return (this->_fruit);
}

FruitNode *FruitNode::getNext(void)
{
    return (_next);
}

FruitNode::~FruitNode()
{
}
