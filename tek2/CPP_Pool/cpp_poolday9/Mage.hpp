/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        Mage();
        Mage(const std::string &name, int level, int strength = 6, int stamina = 6, int intelligence = 12, int spirit = 11, int agility = 7, const std::string race = "Gnome", int range = CLOSE);
        int CloseAttack(void);
        int RangeAttack(void);
        void RestorePower(void);
        ~Mage();

    protected:
    private:
};

#endif /* !MAGE_HPP_ */
