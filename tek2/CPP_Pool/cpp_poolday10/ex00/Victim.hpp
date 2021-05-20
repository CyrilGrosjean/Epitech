/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>

class Victim {
    public:
        Victim();
        Victim(std::string name);
        std::string getName(void) const {return (_name);}
        virtual void getPolymorphed(void) const;
        ~Victim();

    protected:
        std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &s, Victim &victim);

#endif /* !VICTIM_HPP_ */
