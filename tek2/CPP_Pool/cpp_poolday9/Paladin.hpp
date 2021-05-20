/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin : virtual public Warrior, virtual public Priest {
    public:
        Paladin();
        Paladin(const std::string &name, int level, std::string weapon = "hammer", int strength = 9, int stamina = 10, int intelligence = 10, int spirit = 10, int agility = 2, const std::string race = "Human", int range = CLOSE);
        int CloseAttack(void);
        int RangeAttack(void);
        void Heal(void);
        void RestorePower(void);
        int Intercept(void);
        ~Paladin();

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
