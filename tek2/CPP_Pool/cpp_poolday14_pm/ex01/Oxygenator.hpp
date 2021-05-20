/*
** EPITECH PROJECT, 2021
** cpp_poolday14_pm
** File description:
** Oxygenator
*/

#ifndef OXYGENATOR_HPP_
#define OXYGENATOR_HPP_

#include "BaseComponent.hpp"

class Oxygenator
    : public BaseComponent
{
    public:

        Oxygenator();
        virtual ~Oxygenator() {}

        void generateOxygen();
        void useOxygen(int quantity);

    private:
        int _quantity;

};

#endif // OXYGENATOR_HPP_
