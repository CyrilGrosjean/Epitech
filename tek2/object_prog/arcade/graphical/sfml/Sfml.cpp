/*
** EPITECH PROJECT, 2021
** Sfml
** File description:
** file
*/

#include "Sfml.hpp"

Sfml::Sfml()
    : _event()
{
    _window.setFramerateLimit(60);
    _isGameStarted = false;
}

Sfml::~Sfml()
{
}

void Sfml::drawMainMenu()
{
    _window.draw(_mainMenu._background._sprite);
    _window.draw(_mainMenu._title._text);

    _window.draw(_mainMenu._gameRectangle._sprite);
    _window.draw(_mainMenu._gameName._text);
    _window.draw(_mainMenu._previousGame._button._sprite);
    _window.draw(_mainMenu._nextGame._button._sprite);

    _window.draw(_mainMenu._graphicalRectangle._sprite);
    _window.draw(_mainMenu._graphicalName._text);
    _window.draw(_mainMenu._previousGraphical._button._sprite);
    _window.draw(_mainMenu._nextGraphical._button._sprite);

    _window.draw(_mainMenu._start._button._sprite);
    _window.draw(_mainMenu._startText._text);

    _window.draw(_mainMenu._highscoreRect._sprite);
    _window.draw(_mainMenu._highscoreTitle._text);
    _window.draw(_mainMenu._highscoreFirst._text);
    _window.draw(_mainMenu._highscoreSecond._text);
    _window.draw(_mainMenu._highscoreThird._text);

    _window.draw(_mainMenu._insert_coin_button._button._sprite);
    _window.draw(_mainMenu._coin_credits._text);

    _window.draw(_mainMenu._playerName_inputField._playerText._text);
}

void Sfml::input_changeLib()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        _keyboardInput = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        _keyboardInput = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _keyboardInput = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _keyboardInput = 4;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        _keyboardInput = 13;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _keyboardInput = 27;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        _keyboardInput = 32;
}

void Sfml::input_management_main_menu(std::vector<std::string> games, std::vector<std::string> graphicals)
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _mainMenu._clock.getElapsedTime().asMilliseconds() > 180)
        {
            _mainMenu._clock.restart();
            _mousePosition = sf::Mouse::getPosition(_window);
            if (_mainMenu._nextGame.checkClick(sf::Mouse::getPosition(_window)))
                _mainMenu._gameIdx = (_mainMenu._gameIdx + 1 >= games.size()) ? 0 : _mainMenu._gameIdx + 1;
            else if (_mainMenu._previousGame.checkClick(sf::Mouse::getPosition(_window)))
                _mainMenu._gameIdx = (_mainMenu._gameIdx == 0) ? games.size() - 1 : _mainMenu._gameIdx - 1;
            else if (_mainMenu._nextGraphical.checkClick(sf::Mouse::getPosition(_window)))
                _mainMenu._graphicalIdx = (_mainMenu._graphicalIdx + 1 >= graphicals.size()) ? 0 : _mainMenu._graphicalIdx + 1;
            else if (_mainMenu._previousGraphical.checkClick(sf::Mouse::getPosition(_window)))
                _mainMenu._graphicalIdx = (_mainMenu._graphicalIdx == 0) ? graphicals.size() - 1 : _mainMenu._graphicalIdx - 1;
            else if (_mainMenu._insert_coin_button.checkClick(sf::Mouse::getPosition(_window))) {
                _mainMenu._coins++;
                _mainMenu._coin_credits._string = "Credits: " + std::to_string(_mainMenu._coins);
                _mainMenu._coin_credits._text.setString(_mainMenu._coin_credits._string);
            }
            if (_mainMenu._start.checkClick(sf::Mouse::getPosition(_window)) == true && _mainMenu._coins > 0) {
                _isGameStarted = true;
                _mainMenu._coins -= 1;
                _mainMenu._coin_credits._string = "Credits: " + std::to_string(_mainMenu._coins);
                _mainMenu._coin_credits._text.setString(_mainMenu._coin_credits._string);
            }
        }
        if (_event.type == sf::Event::TextEntered)
        {
            _keyboardInput = _event.text.unicode;
            if (_event.text.unicode != 8 && _event.text.unicode != 27 && _event.text.unicode != 13 && _event.text.unicode != 32 && _mainMenu._playerName_inputField._playerInput.size() < 26)
                _mainMenu._playerName_inputField._playerInput += _event.text.unicode;
            else if (_event.text.unicode == 8)
                if (_mainMenu._playerName_inputField._playerInput.size() > 14)
                    _mainMenu._playerName_inputField._playerInput.erase(_mainMenu._playerName_inputField._playerInput.size() - 1);
            _mainMenu._playerName_inputField._playerText._text.setString(_mainMenu._playerName_inputField._playerInput);
        }
        else
            input_changeLib();
    }
}

void Sfml::input_management_game()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            _mousePosition = sf::Mouse::getPosition(_window);
        if (_event.type == sf::Event::TextEntered)
            _keyboardInput = _event.text.unicode;
        else
            input_changeLib();
    }
}

std::unordered_map<std::string, std::string> *Sfml::displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphicals)
{
    if (_window.isOpen())
    {
        if (_isGameStarted == true)
        {
            _mainMenu._music.stop();
            _mainMenuInfo.insert(std::make_pair("NAME", _mainMenu._playerName_inputField._playerInput.substr(_mainMenu._playerName_inputField._playerInput.find(':') + 2, _mainMenu._playerName_inputField._playerInput.size())));
            _mainMenuInfo.insert(std::make_pair("GAME", (games.size() != 0) ? games[_mainMenu._gameIdx] : "UNDEFINED"));
            _mainMenuInfo.insert(std::make_pair("GRAPH", (graphicals.size() != 0) ? graphicals[_mainMenu._graphicalIdx] : "UNDEFINED"));
            close();
            return &_mainMenuInfo;
        }
        if (_isGameStarted == false && _mainMenu._music.getStatus() == sf::Sound::Status::Stopped)
            _mainMenu._music.play();
        input_management_main_menu(games, graphicals);
        _window.clear(sf::Color::Black);
        _mainMenu.set_libraries(games, graphicals);
        _mainMenu.set_highscore();
        drawMainMenu();
        _window.display();
    }
    else
        return &_mainMenuInfo;
    return nullptr;
}

void Sfml::initGame(IGameModule *g_data)
{
    _game.initTiles(g_data->getTiles());
    _game.initObjects(g_data->getObjects());
    if (_mainMenuInfo.size() == 3) {
        _game.initSettings(g_data->getSettings(), _mainMenuInfo["NAME"]);
    }
}

void Sfml::destroyGame(IGameModule *g_date)
{
    _window.clear();
    _game._tiles.clear();
    _game._objects.clear();
    _game._music.stop();
    _mainMenuInfo.clear();
    _isGameStarted = false;
}

void Sfml::updateGame(IGameModule *g_data)
{
    _game.updateObjects(g_data->getObjects());
    _game.updateScore(g_data->getSettings());
}

void Sfml::drawGame(IGameModule *g_data)
{
    _game.drawTiles(_window, g_data->getTiles());
    _game.drawObjects(_window, g_data->getObjects());
    _game.drawText(_window, g_data->getSettings());
}

void Sfml::display(IGameModule *g_data)
{
    if (_window.isOpen())
    {
        input_management_game();
        _window.clear(sf::Color::Black);
        updateGame(g_data);
        drawGame(g_data);
        _window.display();
    }
}

Vector2i Sfml::getEventClick(void)
{
    Vector2i mousePosition = Vector2i(_mousePosition.x, _mousePosition.y);
    _mousePosition = sf::Vector2i(-1, -1);
    return mousePosition;
}

char Sfml::getEventKeyboard(void)
{
    char keyboardInput = _keyboardInput;
    _keyboardInput = 0;
    return keyboardInput;
}

void Sfml::open()
{
    _window.create(sf::VideoMode(960, 960), "Arcade");
}

void Sfml::close()
{
    _window.close();
}