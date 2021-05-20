/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>
#include "IGameModule.hpp"

class Games {
    public:
        Games(std::string name, IGameModule *module): name(name), module(module) {};
        ~Games() {};

        std::string name;
        IGameModule *module;

    protected:
    private:
};

#endif /* !GAME_HPP_ */
