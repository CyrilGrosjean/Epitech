/*
** EPITECH PROJECT, 2021
** cpp_poolday14_am
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
    public:
        Fruit(std::string name, int vitamins);
        std::string const getName(void) const {return (_name);}
        int getVitamins(void) const {return (_vitamins);}
        virtual ~Fruit();

    protected:
        int _vitamins;
        std::string _name;
    private:
};

#endif /* !FRUIT_HPP_ */
