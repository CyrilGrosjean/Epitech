/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : virtual protected Warrior {
    public:
        Hunter();
        Hunter(const std::string &name, int level, std::string weapon = "sword", int strength = 9, int stamina = 9, int intelligence = 5, int spirit = 6, int agility = 25, const std::string race = "Elf", int range = CLOSE);
        int CloseAttack(void);
        int RangeAttack(void);
        void RestorePower(void);

        void Heal(void);
        void TakeDamage(int damage);
        const std::string &getName() const {return (_name);}
        int getLvl() const {return (_level);}
        int getPv() const {return (_pv);}
        int getPower() const {return (_energy);}

        ~Hunter();

    protected:
    private:
};

#endif /* !HUNTER_HPP_ */
