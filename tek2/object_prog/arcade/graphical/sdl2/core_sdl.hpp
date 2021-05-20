/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** core_sdl
*/

#ifndef core_sdl_HPP_
#define core_sdl_HPP_

#include <unordered_map>
#include "../../includes/IDisplayModule.hpp"
#include "../../includes/IGameModule.hpp"
#include "../../includes/GameModule.hpp"
#include "../../includes/Vector.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.hpp"
#include "Menu.hpp"


class core_sdl : IDisplayModule
{
    typedef struct
    {
        unsigned int x;
        unsigned int y;
        std::string text;
        bool underline;
    } Text;

public:
    core_sdl();
    ~core_sdl();
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
    void input_management(std::vector<std::string> games, std::vector<std::string> graphicals);
    void input_changeLib();
    void drawMainMenu();
    void input_management_game();
    void putText(const core_sdl::Text &string);
    void drawSetting( Settings settings);

protected:
private:
    SDL_Renderer *_renderer;
    SDL_Texture *_background;
    TTF_Font *_font;
    SDL_Window *_window;
    sdl::Game _game;
    std::unordered_map<std::string, std::string> _mainMenuInfo;
    sdl::Menu _mainMenu;
    bool _isGameStarted;
    SDL_Event _input;
    std::string _username;
    Vector2i _mousePosition;
    char _keyboardInput;
};

#endif /* !core_sdl_HPP_ */
