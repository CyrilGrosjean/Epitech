/*
** EPITECH PROJECT, 2021
** Main Menu
** File description:
** file
*/

#include "MainMenu.hpp"

MainMenu::MainMenu()
{
    _background = *(new sfml::Sprite("assets/sfml/background.jpeg", sf::IntRect(0, 0, 416, 416), sf::Vector2f(0, 0), sf::Vector2f(2.4, 2.4)));
    _title = *(new sfml::Text("arcade", "assets/sfml/arcade.ttf", 100, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(200, 80)));

    _gameRectangle = *(new sfml::Sprite("assets/sfml/field_blue.png", sf::IntRect(0, 0, 445, 78), sf::Vector2f(260, 265), sf::Vector2f(1, 1)));
    _gameName = *(new sfml::Text("gameName", "assets/sfml/arcade.ttf", 28, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(410, 300), sf::Vector2f(SCRWIDTH, SCRHEIGHT)));
    _previousGame = *(new sfml::Button("assets/sfml/button_left.png", "assets/sfml/button_blue.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(164, 265), sf::Vector2f(1, 1)));
    _nextGame = *(new sfml::Button("assets/sfml/button_right.png", "assets/sfml/button_blue.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(720, 265), sf::Vector2f(1, 1)));
    _gameIdx = 0;

    _graphicalRectangle = *(new sfml::Sprite("assets/sfml/field_blue.png", sf::IntRect(0, 0, 445, 78), sf::Vector2f(260, 365), sf::Vector2f(1, 1)));
    _graphicalName = *(new sfml::Text("graphicalName", "assets/sfml/arcade.ttf", 28, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(410, 400),  sf::Vector2f(SCRWIDTH, SCRHEIGHT)));
    _previousGraphical = *(new sfml::Button("assets/sfml/button_left.png", "assets/sfml/button_blue.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(164, 365), sf::Vector2f(1, 1)));
    _nextGraphical = *(new sfml::Button("assets/sfml/button_right.png", "assets/sfml/button_blue.png", sf::IntRect(0, 0, 81, 78), sf::Vector2f(720, 365), sf::Vector2f(1, 1)));
    _graphicalIdx = 0;

    _start = *(new sfml::Button("assets/sfml/button_start.png", "assets/sfml/field_yellow/png", sf::IntRect(0, 0, 359, 83), sf::Vector2f(300, 480), sf::Vector2f(1, 1)));
    _startText = *(new sfml::Text("Start", "assets/sfml/arcade.ttf", 30, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(480, 515),  sf::Vector2f(SCRWIDTH, SCRHEIGHT)));

    _highscoreRect = *(new sfml::Sprite("assets/sfml/highscore.jpg", sf::IntRect(0, 0, 369, 219), sf::Vector2f(258, 580), sf::Vector2f(1.2, 1.2)));
    _highscoreTitle = *(new sfml::Text("Highscore", "assets/sfml/arcade.ttf", 24, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(480, 610), sf::Vector2f(SCRWIDTH, SCRHEIGHT)));
    _highscoreFirst = *(new sfml::Text("First", "assets/sfml/arcade.ttf", 19, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(480, 675), sf::Vector2f(SCRWIDTH, SCRHEIGHT)));
    _highscoreSecond = *(new sfml::Text("Second", "assets/sfml/arcade.ttf", 19, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(480, 720), sf::Vector2f(SCRWIDTH, SCRHEIGHT)));
    _highscoreThird = *(new sfml::Text("Third", "assets/sfml/arcade.ttf", 19, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(480, 765), sf::Vector2f(SCRWIDTH, SCRHEIGHT)));

    _playerName_inputField = *(new sfml::Input("Enter your name here !", "Player Name : ", "assets/sfml/arcade.ttf", 26, sf::Color(sf::Color::White), sf::Text::Regular, sf::Vector2f(100, 900),  sf::Vector2f(SCRWIDTH, SCRHEIGHT)));

    if (!_music.openFromFile("assets/sfml/menu_song.wav"))
        exit (84);
    _music.play();
    _music.setVolume(60);
    _music.setLoop(true);

    _insert_coin_button = *(new sfml::Button("assets/sfml/insert_coin.png", "assets/sfml/insert_coin.png", sf::IntRect(0, 0, 373, 356), sf::Vector2f(740, 640), sf::Vector2f(0.4, 0.4)));
    _coin_credits = *(new sfml::Text("Credits: ", "assets/sfml/arcade.ttf", 20, sf::Color::White, sf::Text::Style::Regular, sf::Vector2f(730, 790)));
    _coins = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::set_libraries(std::vector<std::string> games, std::vector<std::string> graphicals)
{
    if (games.size() != 0) {
        _gameName._string = games[_gameIdx];
        _gameName._text.setString(_gameName._string);
        _gameName._text.setOrigin(_gameName._text.getGlobalBounds().width / 2, _gameName._text.getGlobalBounds().height / 2);
        _gameName._text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, _gameName._pos.y));
    }
    if (graphicals.size() != 0) {
        _graphicalName._string = graphicals[_graphicalIdx];
        _graphicalName._text.setString(_graphicalName._string);
        _graphicalName._text.setOrigin(_graphicalName._text.getGlobalBounds().width / 2, _graphicalName._text.getGlobalBounds().height / 2);
        _graphicalName._text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, _graphicalName._pos.y));
    }
}

void MainMenu::set_highscore()
{
    std::string file_path = "assets/" + _gameName._string + "/highscore.txt";
    std::ifstream myfile(file_path);

    std::getline(myfile, _highscoreFirst._string);
    _highscoreFirst._text.setString(_highscoreFirst._string);
    _highscoreFirst._text.setOrigin(_highscoreFirst._text.getGlobalBounds().width / 2, _highscoreFirst._text.getGlobalBounds().height / 2);
    _highscoreFirst._text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, _highscoreFirst._pos.y));
    std::getline(myfile, _highscoreSecond._string);
    _highscoreSecond._text.setString(_highscoreSecond._string);
    _highscoreSecond._text.setOrigin(_highscoreSecond._text.getGlobalBounds().width / 2, _highscoreSecond._text.getGlobalBounds().height / 2);
    _highscoreSecond._text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, _highscoreSecond._pos.y));
    std::getline(myfile, _highscoreThird._string);
    _highscoreThird._text.setString(_highscoreThird._string);
    _highscoreThird._text.setOrigin(_highscoreThird._text.getGlobalBounds().width / 2, _highscoreThird._text.getGlobalBounds().height / 2);
    _highscoreThird._text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, _highscoreThird._pos.y));
    myfile.close();
}