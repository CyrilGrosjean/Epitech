/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** file
*/

#include "ncurses.hpp"

extern "C" {
    int entryPoint()
    {
        return 0;
    }

    IDisplayModule *initDisplay()
    {
        Ncurses *ncurses = new Ncurses;
        return reinterpret_cast<IDisplayModule *> (ncurses);
    }

    int forceExitPoint()
    {
        return 0;
    }
}