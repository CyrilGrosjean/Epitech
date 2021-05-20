/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <dlfcn.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>
#include "../includes/IDisplayModule.hpp"
#include "../includes/IGameModule.hpp"
#include "../includes/Display.hpp"
#include "../includes/Games.hpp"
#include "../includes/Vector.hpp"
#include "../includes/Settings.hpp"

namespace core
{
    enum class Scene
    {
        MAIN,
        GAME
    };
    enum class key
    {
        DEFAULT,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
};

class Core
{
public:
    IDisplayModule *display;
    IGameModule *game;

    Core(const std::string defaultLib);
    ~Core();

    int loop();

private:
    void initDisplayModules(void);
    void initGameModules(void);
    int MenuStep();
    int GameStep();
    void ChangeGraphLib(int);
    void check_input(char);
    void ChangeGameLib(int);
    void ArcadeMenu(void);
    void Reset();
    void ReturnMenu();
    void ArcadeGame();
    Scene check_event(char);
    void set_highscore();
    bool _CloseGame;
    std::string _username;
    std::vector<Display> _displays;
    std::vector<Games> _games;
    std::vector<std::string> _gameNames;
    std::vector<std::string> _displayNames;
    core::Scene _scene;
    bool _IsRunning;
    char KeyboardInput;
    Vector2i MouseInput;
    int _indexDisplay;
    int _indexGame;
};

#endif /* !CORE_HPP_ */
