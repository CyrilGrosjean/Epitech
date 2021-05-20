/*
** EPITECH PROJECT, 2021
** cpp_poolday7_pm
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        void stimPaks(int stimPaks);
        const std::string &name();

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    protected:
    private:
        const std::string &_name;
        int _stimPaks;
};

#endif /* !SKAT_HPP_ */
