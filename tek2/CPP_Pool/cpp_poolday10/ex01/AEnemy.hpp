/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>

class AEnemy {
    public:
        AEnemy();
        AEnemy(int hp, const std::string &type);
        std::string *getType() const {return (_type);}
        int getHp(void) const {return (_hp);}
        void setHp(int hp);
        virtual void takeDamage(int damage);
        virtual ~AEnemy();

    protected:
    private:
        int _hp;
        std::string *_type;
};

#endif /* !AENEMY_HPP_ */
