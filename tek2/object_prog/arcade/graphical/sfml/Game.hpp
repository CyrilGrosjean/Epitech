/*
** EPITECH PROJECT, 2021
** Game
** File description:
** sfml game
*/

#ifndef SFML_GAME_H_
#define SFML_GAME_H_

#include <SFML/Audio.hpp>
#include "../../includes/GameModule.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

namespace sfml {
    class Game {
        public:
            Game();
            ~Game();
            void initTiles(std::vector<Object> tiles);
            void initObjects(std::vector<Object> obj);
            void initSettings(Settings settings, std::string playerName);
            void updateObjects(std::vector<Object> obj);
            void updateScore(Settings settings);
            void drawTiles(sf::RenderWindow &, std::vector<Object> tiles);
            void drawObjects(sf::RenderWindow &, std::vector<Object> obj);
            void drawText(sf::RenderWindow &, Settings settings);

            std::vector <sfml::Sprite> _tiles;
            std::vector <sfml::Sprite> _objects;
            sfml::Text _playerName;
            sfml::Text _score;
            sf::Music _music;
        protected:
        private:
    };
}

#endif /* !SFML_GAME_H_ */