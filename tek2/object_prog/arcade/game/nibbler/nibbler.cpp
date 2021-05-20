/*
** EPITECH PROJECT, 2021
** nibbler
** File description:
** file
*/

#include "Nibbler.hpp"
#include "nibbler.hpp"

extern "C" {
    int entryPoint()
    {
        return 0;
    }

    IGameModule *initGame(void)
    {
        Nibbler *nibbler = new Nibbler();
        return reinterpret_cast<IGameModule *> (nibbler);
    }

    int exitPoint()
    {
        return 0;
    }
}