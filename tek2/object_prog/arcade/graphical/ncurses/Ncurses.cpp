/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    this->_isOpened = false;
    this->_gameLaunched = false;
    this->_mouse = Vector2i(-1, -1);
    this->_key = 0;
    this->_gameSelected = 0;
    this->_graphicSelected = 0;
    this->_title.push_back("    ___                        __   ");
    this->_title.push_back("   /   |  ______________ _____/ /__ ");
    this->_title.push_back("  / /| | / ___/ ___/ __ `/ __  / _ \\");
    this->_title.push_back(" / ___ |/ /  / /__/ /_/ / /_/ /  __/");
    this->_title.push_back("/_/  |_/_/   \\___/\\__,_/\\__,_/\\___/ ");
}

Ncurses::~Ncurses()
{
}

void Ncurses::open()
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(0);
    this->_isOpened = true;
    start_color();
    init_pair((short) Texture::TITLE, COLOR_RED, COLOR_BLACK);
    init_pair((short) Texture::NAME, COLOR_GREEN, COLOR_BLACK);
    // init_pair((short) Texture::PLAYER, COLOR_BLUE, COLOR_GREEN);
    // init_pair((short) Texture::ENEMY, COLOR_RED, COLOR_GREEN);
    // init_pair((short) Texture::COLLECTABLE, COLOR_YELLOW, COLOR_GREEN);
    // init_pair((short) Texture::FLOOR, COLOR_BLACK, COLOR_GREEN);
    // init_pair((short) Texture::WALL, COLOR_WHITE, COLOR_BLACK);
}

char Ncurses::getEventKeyboard(void)
{
    return this->_key;
}

Vector2i Ncurses::getEventClick(void)
{
    return this->_mouse;
}

void Ncurses::_handleEvents()
{
    int c = wgetch(stdscr);
    MEVENT event;

    this->_mouse = Vector2i(-1, -1);
    this->_key = 0;
    if (c == KEY_MOUSE) {
        assert(getmouse(&event) == OK);
        this->_mouse = Vector2i(event.x, event.y);
    } else {
        this->_key = c;
    }
}

void Ncurses::close()
{
    endwin();
    this->_isOpened = false;
    this->_gameLaunched = false;
}

void Ncurses::_checkEventsMainMenu(std::vector<std::string> games, std::vector<std::string> displays, int maxX)
{
    if (this->_key == KEY_BACKSPACE || this->_key == KEY_DC || this->_key == 127) {
        if (this->_playerName.size() > 0) {
            this->_playerName = "suppr";
        }
    } else if ((this->_key >= '0' && this->_key <= '9') || (this->_key >= 'a' && this->_key <= 'z') || (this->_key >= 'A' && this->_key <= 'Z')) {
        if (this->_playerName.size() <= 20) {
            this->_playerName = this->_playerName + this->_key;
        }
    } else if (this->_mouse == Vector2i((maxX / 2) - 15, 8)) {
        this->_graphicSelected -= 1;
        if (this->_graphicSelected < 0) {
            this->_graphicSelected = displays.size() - 1;
        }
    } else if (this->_mouse == Vector2i((maxX / 2) + 15, 8)) {
        this->_graphicSelected += 1;
        if (this->_graphicSelected >= displays.size()) {
            this->_graphicSelected = 0;
        }
    } else if (this->_mouse == Vector2i((maxX / 2) - 15, 10)) {
        this->_gameSelected -= 1;
        if (this->_gameSelected < 0) {
            this->_gameSelected = games.size() - 1;
        }
    } else if (this->_mouse == Vector2i((maxX / 2) + 15, 10)) {
        this->_gameSelected += 1;
        if (this->_gameSelected >= games.size()) {
            this->_gameSelected = 0;
        }
    } else if (this->_mouse >= Vector2i((maxX / 2) - (std::string("start").size() / 2), 13)
        && this->_mouse <= Vector2i((maxX / 2) + (std::string("start").size() / 2), 13)) {
            this->_gameLaunched = true;
    }
}

void Ncurses::_displayHighScore(std::vector<std::string> games)
{
    std::string path = "assets/" + games.at(this->_gameSelected) + "/hightscore.txt";
    std::ifstream file(path);
    std::string value;

    std::getline(file, value);
    mvprintw(17, 0, ("1 - " + value).c_str());
    std::getline(file, value);
    mvprintw(18, 0, ("2 - " + value).c_str());
    std::getline(file, value);
    mvprintw(19, 0, ("3 - " + value).c_str());
}

std::unordered_map<std::string, std::string> *Ncurses::displayMainMenu(std::vector<std::string> games, std::vector<std::string> displays)
{
    if (this->_isOpened) {
        int maxX = getmaxx(stdscr);
        this->_handleEvents();
        this->_checkEventsMainMenu(games, displays, maxX);
        if (this->_gameLaunched) {
            this->_menuInfo.insert(std::make_pair("NAME", this->_playerName));
            this->_menuInfo.insert(std::make_pair("GAME", (games.size() != 0) ? games.at(this->_gameSelected) : "UNDEFINED"));
            this->_menuInfo.insert(std::make_pair("GRAPH", (displays.size() != 0) ? displays.at(this->_graphicSelected) : "UNDEFINED"));
            this->close();
            return &(this->_menuInfo);
        } else {
            clear();
            attron(COLOR_PAIR((int) Texture::TITLE));
            mvprintw(0, (maxX / 2) - (this->_title.at(0).size() / 2), this->_title.at(0).c_str());
            mvprintw(1, (maxX / 2) - (this->_title.at(1).size() / 2), this->_title.at(1).c_str());
            mvprintw(2, (maxX / 2) - (this->_title.at(2).size() / 2), this->_title.at(2).c_str());
            mvprintw(3, (maxX / 2) - (this->_title.at(3).size() / 2), this->_title.at(3).c_str());
            mvprintw(4, (maxX / 2) - (this->_title.at(4).size() / 2), this->_title.at(4).c_str());
            attroff(COLOR_PAIR((int) Texture::TITLE));

            int length = displays.at(this->_graphicSelected).size();
            mvprintw(8, (maxX / 2) - 15, "<");
            attron(COLOR_PAIR((int) Texture::NAME));
            mvprintw(8, (maxX / 2) - (length / 2), displays.at(this->_graphicSelected).c_str());
            attroff(COLOR_PAIR((int) Texture::NAME));
            mvprintw(8, (maxX / 2) + 15, ">");

            length = games.at(this->_gameSelected).size();
            mvprintw(10, (maxX / 2) - 15, "<");
            attron(COLOR_PAIR((int) Texture::NAME));
            mvprintw(10, (maxX / 2) - (length / 2), games.at(this->_gameSelected).c_str());
            attroff(COLOR_PAIR((int) Texture::NAME));
            mvprintw(10, (maxX / 2) + 15, ">");

            attron(COLOR_PAIR((int) Texture::TITLE));
            mvprintw(13, (maxX / 2) - (std::string("start").length() / 2), "Start");
            attroff(COLOR_PAIR((int) Texture::TITLE));

            length = std::string("Name: ").size() + this->_playerName.size();
            mvprintw(15, (maxX / 2) - (length / 2), std::string("Name: " + this->_playerName).c_str());
            this->_displayHighScore(games);
            refresh();
            usleep(100000);
        }
    }
    return nullptr;
}

void Ncurses::display(IGameModule *game)
{
    if (this->_isOpened) {
        this->_handleEvents();
        clear();
        std::vector<Object> tiles = game->getTiles();
        std::vector<Object> objects = game->getObjects();

        for (Object object : tiles) {
            if (object.getContent() == Content::WALL) {
                this->_displayWall(object);
            } else if (object.getContent() == Content::FLOOR) {
                this->_displayFloor(object);
            } else {
                this->_displayOther(object);
            }
        }
        for (Object object : objects) {
            if (object.getContent() == Content::PLAYER) {
                this->_displayPlayer(object);
            } else if (object.getContent() == Content::ENEMY) {
                this->_displayEnemy(object);
            } else if (object.getContent() == Content::COLLECTABLE) {
                this->_displayCollectable(object);
            } else {
                this->_displayOther(object);
            }
        }
        int maxX = getmaxx(stdscr);
        int maxY = getmaxy(stdscr);
        mvprintw(maxY - 1, maxX - 10, std::to_string((int) game->getSettings().getScore()).c_str());
        refresh();
        usleep(10000);
    }
}

void Ncurses::_displayWall(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        // attron(COLOR_PAIR((int) Texture::WALL));
        mvprintw(pos.y, pos.x, content.c_str());
        // attroff(COLOR_PAIR((int) Texture::WALL));
    }
}

void Ncurses::_displayFloor(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        // attron(COLOR_PAIR((int) Texture::FLOOR));
        mvprintw(pos.y, pos.x, content.c_str());
        // attroff(COLOR_PAIR((int) Texture::FLOOR));
    }
}

void Ncurses::_displayPlayer(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        // attron(COLOR_PAIR((int) Texture::PLAYER));
        mvprintw(pos.y, pos.x, content.c_str());
        // attroff(COLOR_PAIR((int) Texture::PLAYER));
    }
}

void Ncurses::_displayCollectable(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        // attron(COLOR_PAIR((int) Texture::COLLECTABLE));
        mvprintw(pos.y, pos.x, content.c_str());
        // attroff(COLOR_PAIR((int) Texture::COLLECTABLE));
    }
}

void Ncurses::_displayEnemy(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        // attron(COLOR_PAIR((int) Texture::ENEMY));
        mvprintw(pos.y, pos.x, content.c_str());
        // attroff(COLOR_PAIR((int) Texture::ENEMY));
    }
}

void Ncurses::_displayOther(Object object)
{
    std::ifstream file(object.getFilePath() + ".txt");
    std::string content;

    std::getline(file, content);
    if (object.isActive()) {
        Vector2i pos = object.getCoords() / (int) object.getSize();
        mvprintw(pos.y, pos.x, content.c_str());
    }
}