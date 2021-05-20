/*
** EPITECH PROJECT, 2021
** SFML
** File description:
** header file class
*/

#ifndef SFMLCLASS_H_
#define SFMLCLASS_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include "../../includes/IDisplayModule.hpp"
#include "../../includes/IGameModule.hpp"
#include "../../includes/GameModule.hpp"
#include "../../includes/Vector.hpp"
#include "MainMenu.hpp"
#include "Game.hpp"

class Sfml : IDisplayModule {
    public:
        Sfml();
        ~Sfml();
        void open();
        std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphicals);
        void display(IGameModule *);
        Vector2i getEventClick(void);
        char getEventKeyboard(void);
        void initGame(IGameModule *);
        void updateGame(IGameModule *);
        void drawGame(IGameModule *);
        void destroyGame(IGameModule *);
        void close();

        void input_management_main_menu(std::vector<std::string> games, std::vector<std::string> graphicals);
        void input_management_game();
        void input_changeLib();
        void drawMainMenu();

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        MainMenu _mainMenu;
        std::unordered_map<std::string, std::string> _mainMenuInfo;
        sfml::Game _game;
        bool _isGameStarted;
        sf::Vector2i _mousePosition;
        char _keyboardInput;
};

#endif /* !SFMLCLASS_H_ */