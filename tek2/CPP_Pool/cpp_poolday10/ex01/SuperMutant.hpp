/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** SuperMutant
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant : virtual public AEnemy {
    public:
        SuperMutant();
        void takeDamage(int damage) override;
        ~SuperMutant();

    protected:
    private:
};

#endif /* !SUPERMUTANT_HPP_ */
