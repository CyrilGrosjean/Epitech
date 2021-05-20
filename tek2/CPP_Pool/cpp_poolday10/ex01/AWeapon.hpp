/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>

class AWeapon {
    public:
        AWeapon();
        AWeapon(const std::string &name, int apcost, int damage);
        std::string *getName(void) const {return (_name);}
        int getAPCost(void) const {return (_apcost);}
        int getDamage(void) const {return (_damage);}
        virtual void attack(void) const = 0;
        virtual ~AWeapon();

    protected:
    private:
        std::string *_name;
        int _apcost;
        int _damage;
};

#endif /* !AWEAPON_HPP_ */
