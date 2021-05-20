/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** PlasmaRifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : virtual public AWeapon {
    public:
        PlasmaRifle();
        void attack(void) const override;
        ~PlasmaRifle();

    protected:
    private:

};

#endif /* !PLASMARIFLE_HPP_ */
