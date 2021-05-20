/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../../includes/GameModule.hpp"
#include <iostream>
#include <string>
#include "set_asset.hpp"

namespace sdl
{
    class Game
    {
    public:
        Game();
        ~Game();
        void initTiles(std::vector<Object> tiles, SDL_Renderer *_renderer);
        void initObjects(std::vector<Object> obj, SDL_Renderer *_renderer);
        void updateTiles(std::vector<Object> tiles,SDL_Renderer *_renderer);
        void updateObjects(std::vector<Object> obj, SDL_Renderer *_renderer);
        void drawTiles(SDL_Renderer *, std::vector<Object> tiles);
        void drawObjects(SDL_Renderer *, std::vector<Object> obj);

        std::vector<sdl::set_asset> _tiles;
        std::vector<sdl::set_asset> _objects;

    protected:
    private:
    };
}

#endif /* !GAME_HPP_ */
