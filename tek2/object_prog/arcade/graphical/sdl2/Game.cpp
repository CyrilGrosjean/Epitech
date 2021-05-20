/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** Game
*/

#include "Game.hpp"

sdl::Game::Game()
{
}

sdl::Game::~Game()
{
}

void sdl::Game::initTiles(std::vector<Object> tiles, SDL_Renderer *_renderer)
{
    sdl::set_asset tile;

    if (tiles.size() != 0)
        for (std::vector<Object>::iterator it = tiles.begin(); it != tiles.end(); it++)
        {
            tile = *(new sdl::set_asset(_renderer, it->getFilePath() + ".png", SDL_Rect{it->getCoords().x, it->getCoords().y, (int)it->getSize(), (int)it->getSize()}, SDL_Rect{32, 32, 32, 32}, 1.0, 1.0));
            _tiles.push_back(tile);
        }
}

void sdl::Game::initObjects(std::vector<Object> objects, SDL_Renderer *_renderer)
{
    sdl::set_asset object;

    if (objects.size() != 0)
        for (std::vector<Object>::iterator it = objects.begin(); it != objects.end(); it++)
        {
            object = *(new sdl::set_asset(_renderer, it->getFilePath() + ".png", SDL_Rect{it->getCoords().x, it->getCoords().y, (int)it->getSize(), (int)it->getSize()}, SDL_Rect{32, 32, 32, 32}, 1.0, 1.0));
            _objects.push_back(object);
        }
}

void sdl::Game::updateTiles(std::vector<Object> tiles, SDL_Renderer *_renderer)
{
    tiles.clear();
    initObjects(tiles, _renderer);
    if (tiles.size() != 0)
        for (int i = 0; i < tiles.size() && i < _tiles.size(); i++)
        {
            _tiles[i]._rect.x = tiles[i].getCoords().x;
            _tiles[i]._rect.y = tiles[i].getCoords().y;
        }
}

void sdl::Game::updateObjects(std::vector<Object> objects, SDL_Renderer *_renderer)
{
    int speed = 1;
    _objects.clear();
    initObjects(objects, _renderer);
    if (objects.size() != 0)
        for (int i = 0; i < objects.size() && i < _objects.size(); i++)
        {
            if (_objects[i]._rect.x > objects[i].getCoords().x)
                _objects[i]._rect.x -= 32;
            else if (_objects[i]._rect.x < objects[i].getCoords().x)
                _objects[i]._rect.x += 32;
            if (_objects[i]._rect.y > objects[i].getCoords().y)
                _objects[i]._rect.y -= 32;
            else if (_objects[i]._rect.y < objects[i].getCoords().y)
                _objects[i]._rect.y += 32;
        }
}

void sdl::Game::drawObjects(SDL_Renderer *_renderer, std::vector<Object> objects)
{
    int i = 0;
    SDL_Rect rect;
    if (_objects.size() != 0)
        for (std::vector<sdl::set_asset>::iterator it = _objects.begin(); it != _objects.end(); it++, i++)
            if (objects[i].isActive())
            {
                SDL_RenderCopy(_renderer, it->_texture, NULL, &it->_rect);
                SDL_DestroyTexture(it->_texture);
            }
    // window.draw(it->_sprite);
}

void sdl::Game::drawTiles(SDL_Renderer *_renderer, std::vector<Object> tiles)
{
    int i = 0;

    SDL_Rect rect;
    rect.x = 1920 / 2 - (21 * 31 / 2) + 1 * 21;
    rect.y = 1080 / 2 - (21 * 31 / 2) + 1 * 21;
    rect.h = 21;
    rect.w = 21;
    if (_tiles.size() != 0)

        for (std::vector<sdl::set_asset>::iterator it = _tiles.begin(); it != _tiles.end(); it++, i++)
            if (tiles[i].isActive())
            {
                SDL_RenderCopy(_renderer, it->_texture, NULL, &it->_rect);
            }
    // window.draw(it->_sprite);
}