/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &name);
        void recoverAP(void);
        void equip(AWeapon *weapon) {_weapon = weapon;}
        void attack(AEnemy *enemy);
        std::string *getName(void) const {return (_name);}
        int getAp(void) const {return (_ap);}
        AWeapon *getWeapon(void) const {return (_weapon);}
        ~Character();

    protected:
    private:
        std::string *_name;
        int _ap;
        AWeapon *_weapon;

};

std::ostream &operator<<(std::ostream &s, Character &charac);

#endif /* !CHARACTER_HPP_ */
