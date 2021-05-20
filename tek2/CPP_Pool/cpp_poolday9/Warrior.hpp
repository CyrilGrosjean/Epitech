/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character {
    public:
        Warrior();
        Warrior(const std::string &name, int level, std::string weapon = "hammer", int strength = 12, int stamina = 12, int intelligence = 6, int spirit = 5, int agility = 7, const std::string race = "Dwarf", int range = CLOSE);
        int CloseAttack(void);
        int RangeAttack(void);
        std::string getWeaponName(void) const {return (_weaponName);}
        ~Warrior();

    protected:
        std::string _weaponName;
    private:
};

#endif /* !WARRIOR_HPP_ */
