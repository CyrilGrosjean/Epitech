/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <vector>
#include "Object.hpp"
#include "Settings.hpp"
#include "Vector.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual bool update(Vector2i mouse, char key) = 0;
        virtual void handleMouseEvent(Vector2i mouse) = 0;
        virtual void handleKeyEvent(char key) = 0;
        virtual void reset(void) = 0;

    virtual std::vector<Object> getObjects(void) const = 0;
    virtual std::vector<Object> getTiles(void) const = 0;
    virtual Settings getSettings(void) const = 0;
};

#endif /* !IGAMEMODULE_HPP_ */
