/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        int nbFruits(void) const {return (_fruitNumber);}
        bool putFruit(Fruit *f);
        Fruit *pickFruit(void);
        FruitNode *head(void) const;
        virtual ~FruitBox();

    protected:
        FruitNode *_head;
        int _size;
        int _fruitNumber;
    private:
};

#endif /* !FRUITBOX_HPP_ */
