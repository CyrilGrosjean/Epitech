/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string str);
        void diagnose(SickKoala *patient);
        void timeCheck(void);
        std::string getName(void);
        ~KoalaDoctor(void);

    protected:
    private:
        std::string name;
        bool isWorking;
};

#endif /* !KOALADOCTOR_HPP_ */
