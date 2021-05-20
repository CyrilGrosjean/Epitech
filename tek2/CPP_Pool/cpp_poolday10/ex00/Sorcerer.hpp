/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer();
        Sorcerer(std::string name, std::string title);
        std::string getName(void) const {return (_name);}
        std::string getTitle(void) const {return (_title);}
        void polymorph(const Victim &victim) const;
        ~Sorcerer();

    protected:
        std::string _name;
        std::string _title;
    private:
};

std::ostream &operator<<(std::ostream &s, Sorcerer &sorcerer);

#endif /* !SORCERER_HPP_ */
