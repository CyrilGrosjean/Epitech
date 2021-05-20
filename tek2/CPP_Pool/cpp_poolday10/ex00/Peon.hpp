/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : virtual public Victim {
    public:
        Peon();
        Peon(std::string name);
        void getPolymorphed(void) const;
        ~Peon();

    protected:
    private:
};

#endif /* !PEON_HPP_ */
