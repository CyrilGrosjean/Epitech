/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : virtual public Mage {
    public:
        Priest();
        Priest(const std::string &name, int level, int strength = 4, int stamina = 4, int intelligence = 42, int spirit = 21, int agility = 2, const std::string race = "Orc", int range = CLOSE);
        int CloseAttack(void);
        void Heal(void);
        ~Priest();

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
