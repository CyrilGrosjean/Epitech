/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int identifier);
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string filename);
        void timeCheck(void);
        int getID(void);
        ~KoalaNurse(void);
    protected:
    private:
        int id;
        bool isWorking;
};

#endif /* !KOALANURSE_HPP_ */
