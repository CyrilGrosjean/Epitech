/*
** EPITECH PROJECT, 2021
** pacman
** File description:
** file
*/

#include "pacman.hpp"

extern "C" {
    int entryPoint()
    {
        return 0;
    }

    IGameModule *initGame(void)
    {
        Pacman *pacman = new Pacman();
        return reinterpret_cast<IGameModule *> (pacman);
    }

    int exitPoint()
    {
        return (0);
    }
}