/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** GameModule
*/

#ifndef GAMEMODULE_HPP_
#define GAMEMODULE_HPP_

#include "IGameModule.hpp"
#include "Object.hpp"

class GameModule : public IGameModule {
    public:
        GameModule() {};
        ~GameModule() {};

        bool update(Vector2i mouse, char key) override {return true;};
        void handleMouseEvent(Vector2i mouse) override {};
        void handleKeyEvent(char key) override {};
        std::vector<Object> getObjects(void) const override {return this->_objects;};
        std::vector<Object> getTiles(void) const override {return this->_tiles;};
        Settings getSettings(void) const override {return this->_settings;};

    protected:
        std::vector<Object> _tiles;
        std::vector<Object> _objects;
        Settings _settings;
    private:
};

#endif /* !GAMEMODULE_HPP_ */
