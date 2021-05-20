/*
** EPITECH PROJECT, 2021
** IDisplayModule
** File description:
** INterface for display libraries
*/

#ifndef IDISPLAYMODULE_H_
#define IDISPLAYMODULE_H_

#include <unordered_map>
#include "IGameModule.hpp"
#include "Vector.hpp"

class IDisplayModule
{
public:
    virtual ~IDisplayModule() = default;
    virtual void initGame(IGameModule *module) = 0;
    virtual void destroyGame(IGameModule *module) = 0;
    virtual void open(void) = 0;
    virtual std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphicals) = 0;
    virtual void display(IGameModule *module) = 0;
    virtual Vector2i getEventClick(void) = 0;
    virtual char getEventKeyboard(void) = 0;
    virtual void close(void) = 0;
};

#endif /* !IDISPLAYMODULE_H_ */