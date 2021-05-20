/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <curses.h>
#include <assert.h>
#include <unistd.h>
#include <unordered_map>
#include <fstream>
#include "../../includes/IDisplayModule.hpp"
#include "../../includes/IGameModule.hpp"

enum class Texture {
    TITLE = 1,
    NAME = 2,
    PLAYER = 3,
    ENEMY = 4,
    COLLECTABLE = 5,
    FLOOR = 6,
    WALL = 7,
};

class Ncurses : public IDisplayModule {
    public:
        Ncurses();
        ~Ncurses();

        void open();
        std::unordered_map<std::string, std::string> *displayMainMenu(std::vector<std::string> games, std::vector<std::string> displays);
        void display(IGameModule *game);

        void initGame(IGameModule *game) {};
        void destroyGame(IGameModule *game) {};

        Vector2i getEventClick(void);
        char getEventKeyboard(void);
        void close(void);

    protected:
        void _handleEvents(void);
        void _checkEventsMainMenu(std::vector<std::string> games, std::vector<std::string> displays, int maxX);
        void _displayHighScore(std::vector<std::string> games);

        void _displayWall(Object wall);
        void _displayFloor(Object floor);
        void _displayPlayer(Object player);
        void _displayCollectable(Object collectable);
        void _displayEnemy(Object enemy);
        void _displayOther(Object other);
    private:
        Vector2i _mouse;
        char _key;

        // ~ MAIN MENU ~
        std::vector<std::string> _title;
        bool _isOpened;
        bool _gameLaunched;

        int _gameSelected;
        int _graphicSelected;
        std::unordered_map<std::string, std::string> _menuInfo;
        std::string _playerName;
        // -----
};

#endif /* !NCURSES_HPP_ */
