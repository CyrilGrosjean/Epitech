/*
** EPITECH PROJECT, 2021
** cpp_poolday7_pm
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string name);
        ~KoalaBot();

    protected:
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _name;
};

#endif /* !KOALABOT_HPP_ */
