/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>

class SickKoala {
    public:
        SickKoala(std::string name);
        void poke(void);
        bool takeDrug(std::string drug);
        void overDrive(std::string text);
        std::string getName(void);
        ~SickKoala(void);
    protected:
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
