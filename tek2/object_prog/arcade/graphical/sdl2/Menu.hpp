/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <fstream>
#include "../../includes/Vector.hpp"
#include <vector>

namespace sdl
{

    class Menu
    {
    public:
        Menu();
        ~Menu();
        size_t _gameIdx;
        size_t _graphicalIdx;
        std::string _username;
        void set_libraries(std::vector<std::string> games, std::vector<std::string> graphicals);
        void set_highscore(void);
    };
}

#endif /* !MENU_HPP_ */
