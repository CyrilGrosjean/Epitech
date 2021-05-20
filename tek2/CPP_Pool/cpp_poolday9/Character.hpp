/*
** EPITECH PROJECT, 2021
** cpp_poolday9
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

class Character {
    public:
        Character();
        Character(const std::string &name, int level, int strength = 5, int stamina = 5, int intelligence = 5, int spirit = 5, int agility = 5, const std::string race = "Human", int range = CLOSE);
        const std::string &getName() const {return (_name);}
        int getLvl() const {return (_level);}
        int getPv() const {return (_pv);}
        int getPower() const {return (_energy);}
        int CloseAttack(void);
        void Heal(void);
        int RangeAttack(void);
        void RestorePower(void);
        void TakeDamage(int damage);
        ~Character();

        enum AttackRange {
            CLOSE,
            RANGE,
        };
        AttackRange Range;
    protected:
        std::string _name;
        int _level;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
        std::string _class;
        int _pv;
        int _energy;
        std::string _race;
    private:
};

#endif /* !CHARACTER_HPP_ */
