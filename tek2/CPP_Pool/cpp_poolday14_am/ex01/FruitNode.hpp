/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        FruitNode();
        bool push(Fruit *fruit);
        Fruit *pick(void);
        FruitNode *getNext(void);
        ~FruitNode();

    protected:
        Fruit *_fruit;
        FruitNode *_next;
    private:
};

#endif /* !FRUITNODE_HPP_ */
