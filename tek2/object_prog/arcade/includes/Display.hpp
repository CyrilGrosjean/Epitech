/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <string>
#include "IDisplayModule.hpp"

class Display {
    public:
        Display(std::string name, IDisplayModule *module): name(name), module(module) {};
        ~Display() {};

        std::string name;
        IDisplayModule *module;

    protected:
    private:
};

#endif /* !DISPLAY_HPP_ */
