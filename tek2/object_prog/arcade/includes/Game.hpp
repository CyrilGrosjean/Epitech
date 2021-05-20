/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Game
*/

#ifndef GAMES_HPP_
#define GAMES_HPP_

#include <string>
#include "IGameModule.hpp"

class Games {
    public:
        Games(std::string name, IGameModule *module): name(name), module(module) {};
        ~Games();

        std::string name;
        IGameModule *module;

    protected:
    private:
};

#endif /* !GAMES_HPP_ */
