/*
** EPITECH PROJECT, 2021
** Main menu
** File description:
** Header file
*/

#ifndef SFML_MAINMENU_H_
#define SFML_MAINMENU_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Sprite.hpp"
#include "Text.hpp"
#include "Input.hpp"
#include "Button.hpp"

const int SCRWIDTH = 960;
const int SCRHEIGHT = 960;

class MainMenu {
    public:
        MainMenu();
        ~MainMenu();
        sfml::Sprite _background;
        sfml::Text _title;
        sfml::Input _playerName_inputField;

        sfml::Text _gameName;
        sfml::Sprite _gameRectangle;
        sfml::Button _nextGame;
        sfml::Button _previousGame;
        size_t _gameIdx;

        sfml::Text _graphicalName;
        sfml::Sprite _graphicalRectangle;
        sfml::Button _nextGraphical;
        sfml::Button _previousGraphical;
        size_t _graphicalIdx;

        sfml::Sprite _highscoreRect;
        sfml::Text _highscoreTitle;
        sfml::Text _highscoreFirst;
        sfml::Text _highscoreSecond;
        sfml::Text _highscoreThird;

        sfml::Button _start;
        sfml::Text _startText;

        sfml::Button _insert_coin_button;
        sfml::Text _coin_credits;
        size_t _coins;

        sf::Clock _clock;
        sf::Music _music;

        void set_libraries(std::vector<std::string> games, std::vector<std::string> graphicals);
        void set_highscore(void);
};

#endif /* !SFML_MAINMENU_H_ */