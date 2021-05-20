/*
** EPITECH PROJECT, 2021
** sdl2
** File description:
** file
*/

#include "sdl2.hpp"

extern "C" {
    int entryPoint()
    {
        std::cout << "My test" << std::endl;
        return 0;
    }


    IDisplayModule *initDisplay()
    {
        core_sdl *sdl = new core_sdl;
        return reinterpret_cast<IDisplayModule *> (sdl);
    }

    int myPuts(std::string str)
    {
        std::cout << "My message : " << str << std::endl;
        return 0;
    }
}