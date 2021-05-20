/*
** EPITECH PROJECT, 2021
** sfml
** File description:
** file
*/

#include "sfml.hpp"

extern "C" {
    int entryPoint()
    {
        return 0;
    }

    IDisplayModule *initDisplay()
    {
        Sfml *sfml = new Sfml;
        return reinterpret_cast<IDisplayModule *> (sfml);
    }

    int forceExitPoint()
    {
        return 0;
    }
}