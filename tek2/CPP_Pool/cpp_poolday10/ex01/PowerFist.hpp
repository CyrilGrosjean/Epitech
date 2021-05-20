/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : virtual public AWeapon {
    public:
        PowerFist();
        void attack(void) const override;
        ~PowerFist();

    protected:
    private:
};

#endif /* !POWERFIST_HPP_ */
