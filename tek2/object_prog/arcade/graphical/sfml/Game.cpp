/*
** EPITECH PROJECT, 2021
** Game
** File description:
** file
*/

#include "Game.hpp"

sfml::Game::Game()
{
}

sfml::Game::~Game()
{
}

void sfml::Game::initTiles(std::vector<Object> tiles)
{
    sfml::Sprite tile;

    if (tiles.size() != 0)
        for (std::vector<Object>::iterator it = tiles.begin(); it != tiles.end(); it++)
        {
            tile = *(new sfml::Sprite(it->getFilePath() + ".png", sf::IntRect(0, 0, it->getSize(), it->getSize()), sf::Vector2f(it->getCoords().x, it->getCoords().y), sf::Vector2f(1, 1)));
            _tiles.push_back(tile);
        }
}

void sfml::Game::initObjects(std::vector<Object> objects)
{
    sfml::Sprite object;

    if (objects.size() != 0)
        for (std::vector<Object>::iterator it = objects.begin(); it != objects.end(); it++)
        {
            object = *(new sfml::Sprite(it->getFilePath() + ".png", sf::IntRect(0, 0, it->getSize(), it->getSize()), sf::Vector2f(it->getCoords().x, it->getCoords().y), sf::Vector2f(1, 1)));
            _objects.push_back(object);
        }
}

void sfml::Game::initSettings(Settings settings, std::string playerName)
{
    _score = *(new sfml::Text("Score : " + std::to_string(settings.getScore()), "assets/sfml/arcade.ttf", 24, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(50, 50)));
    _playerName = *(new sfml::Text("Player : " + playerName, "assets/sfml/arcade.ttf", 24, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(50, 100)));
    if (!_music.openFromFile(settings.getMusicPath()))
        exit (84);
    _music.play();
    _music.setVolume(60);
    _music.setLoop(true);
}

void sfml::Game::updateObjects(std::vector<Object> objects)
{
    if (objects.size() != _objects.size()) {
        _objects.clear();
        initObjects(objects);
    }
    if (objects.size() != 0 && _objects.size() == objects.size())
        for (int i = 0; i < objects.size(); i++)
        {
            _objects[i]._pos = sf::Vector2f(objects[i].getCoords().x, objects[i].getCoords().y);
            _objects[i]._sprite.setPosition(sf::Vector2f(_objects[i]._pos.x, _objects[i]._pos.y));
            if (objects[i].getFilePath() != _objects[i]._filepath) {
                _objects[i]._filepath = objects[i].getFilePath();
                if (!_objects[i]._texture.loadFromFile(_objects[i]._filepath  + ".png"))
                    exit (84);
            }
            _objects[i]._sprite.setTexture(_objects[i]._texture);
        }
}

void sfml::Game::updateScore(Settings settings)
{
    if (_score._string != "Score : " + std::to_string(settings.getScore())) {
        _score._string = "Score : " + std::to_string(settings.getScore());
        _score._text.setString(_score._string);
    }
}

void sfml::Game::drawObjects(sf::RenderWindow &window, std::vector<Object> objects)
{
    int i = 0;

    if (_objects.size() != 0 && _objects.size() == objects.size())
        for (std::vector<sfml::Sprite>::iterator it = _objects.begin(); it != _objects.end(); it++, i++)
            if (objects[i].isActive())
                window.draw(it->_sprite);
}

void sfml::Game::drawTiles(sf::RenderWindow &window, std::vector<Object> tiles)
{
    int i = 0;

    if (_tiles.size() != 0)
        for (std::vector<sfml::Sprite>::iterator it = _tiles.begin(); it != _tiles.end(); it++, i++)
            if (tiles[i].isActive())
                window.draw(it->_sprite);
}

void sfml::Game::drawText(sf::RenderWindow &window, Settings settings)
{
    window.draw(_playerName._text);
    window.draw(_score._text);
}