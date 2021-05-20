/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** Core
*/

#include "Core.hpp"

void Core::initDisplayModules(void)
{
    DIR *dir;
    struct dirent *file;
    IDisplayModule *(*init)(void);
    struct stat info;

    dir = opendir("./lib/");
    if (dir != NULL)
    {
        for (file = readdir(dir); file != NULL; file = readdir(dir))
        {
            std::string name(file->d_name);
            if (stat(("./lib/" + name).c_str(), &info) != 0)
                continue;
            else if (info.st_mode & S_IFDIR)
                continue;
            void *hndl = dlopen(("./lib/" + name).c_str(), RTLD_LAZY);
            if (hndl == NULL) {
                continue;
            }
            init = reinterpret_cast<IDisplayModule *(*)(void)>(dlsym(hndl, "initDisplay"));
            if (init == NULL)
            {
                dlclose(hndl);
                continue;
            }
            std::string displayName = name.substr(name.find('_') + 1, name.find('.') - name.find('_') - 1);
            std::cout << displayName << " graphical library loaded" << std::endl;
            this->_displays.push_back(*(new Display(displayName, init())));
            this->_displayNames.push_back(displayName);
        }
        closedir(dir);
    }
    else
    {
        std::cerr << "Can't found lib/ repository." << std::endl;
        exit(84);
    }
}

void Core::initGameModules(void)
{
    DIR *dir;
    struct dirent *file;
    IGameModule *(*init)(void);

    dir = opendir("./lib/");
    if (dir != NULL)
    {
        for (file = readdir(dir); file != NULL; file = readdir(dir))
        {
            std::string name(file->d_name);
            void *hndl = dlopen(("./lib/" + name).c_str(), RTLD_LAZY);
            if (hndl == NULL)
                continue;
            init = reinterpret_cast<IGameModule *(*)(void)>(dlsym(hndl, "initGame"));
            if (init == NULL)
            {
                dlclose(hndl);
                continue;
            }
            std::string gameName = name.substr(name.find('_') + 1, name.find('.') - name.find('_') - 1);
            std::cout << gameName << " game library loaded" << std::endl;
            this->_games.push_back(*(new Games(gameName, init())));
            this->_gameNames.push_back(gameName);
        }
        closedir(dir);
    }
    else
    {
        std::cerr << "Can't found lib/ repository." << std::endl;
        exit(84);
    }
}

Core::Core(std::string lib)
{

    _username = "";
    _CloseGame = false;
    this->initDisplayModules();
    this->initGameModules();
    int index = 0;
    for (std::string name : this->_displayNames)
    {
        std::cout << lib << std::endl;
        std::cout << name << std::endl;

        if (lib.find(name) != std::string::npos)
        {
            break;
        }
        index++;
    }
    //
    this->_indexDisplay = index;
    std::cout << "test" << std::endl;
    this->display = this->_displays.at(_indexDisplay).module;
    this->game = nullptr;
    this->_scene = core::Scene::MAIN;
    this->_IsRunning = false;
    this->loop();
}

void Core::ChangeGraphLib(int i)
{
        if (this->_games.size() != 1){
    if (i == 1)
        this->_indexDisplay += 1;
    else
        this->_indexDisplay -= 1;
    if (this->_indexDisplay > ((int)this->_displays.size() - 1))
        this->_indexDisplay = 0;
    else if (this->_indexDisplay < 0)
        this->_indexDisplay = ((int)this->_displays.size() - 1);
    std::cout << _indexDisplay << std::endl;
    this->display->close();
    this->display = this->_displays.at(_indexDisplay).module;
    this->display->open();
    if( this->_scene == core::Scene::GAME)
        this->display->initGame(this->game);
    }
}

void Core::ChangeGameLib(int i)
{
    if (this->_games.size() != 1){
    if (i == 1)
        this->_indexGame += 1;
    else
        this->_indexGame -= 1;
    if (this->_indexGame > ((int)this->_games.size() - 1))
        this->_indexGame = 0;
    else if (this->_indexGame < 0)
        this->_indexGame = ((int)this->_games.size() - 1);
    this->display->destroyGame(this->game);
    this->game = this->_games.at(_indexGame).module;
    this->display->initGame(this->game);
    }
}

void Core::ReturnMenu()
{
    this->display->destroyGame(this->game);
    this->_scene = core::Scene::MAIN;
}

void Core::Reset()
{
    this->game->reset();
}

void Core::check_input(char c)
{
    switch (c)
    {
    case 1:
        this->ChangeGraphLib(1);
        break;
    case 2:
        this->ChangeGraphLib(-1);
        break;
    case 4:
        this->ChangeGameLib(1);
        break;
    case 3:
        this->ChangeGameLib(-1);
        break;
    case 13:
        this->Reset();
        break;
    case 27:
        this->_IsRunning = false;
        break;
    case 32:
    this->ReturnMenu();
        break;
    default:
        // this->game.init();
        break;
    }
}

void Core::ArcadeMenu(void)
{
    if (std::unordered_map<std::string, std::string> *map = this->display->displayMainMenu(_gameNames, _displayNames))
    {
        this->_scene = core::Scene::GAME;
        if ((*map).size() != 0)
        {
            this->_username = (*map)["NAME"];
            std::cout << "Setting : " << this->_username << " as player name" << std::endl;
            for (size_t i = 0; i < this->_displays.size(); i++)
                if (this->_displays[i].name.compare((*map)["GRAPH"]) == 0)
                {
                    this->display = this->_displays[i].module;
                    std::cout << "Setting : " << _displays[i].name << " as graphical library" << std::endl;
                     this->_indexDisplay = i;
                }
            for (size_t i = 0; i < this->_games.size(); i++)
                if (this->_games[i].name.compare((*map)["GAME"]) == 0)
                {
                    this->game = this->_games[i].module;
                    std::cout << "Setting : " << _games[i].name << " as game library" << std::endl;
                    this->_indexGame = i;
                }
            this->display->open();
            this->display->initGame(this->game);
        }
        else
            std::cout << "Map is empty" << std::endl;
    }
    // MAIN MENU LOOP
}

bool compare_score(std::pair<std::string, size_t> &a, std::pair<std::string, size_t> &b)
{
    return a.second > b.second;
}

void Core::set_highscore(void)
{
    std::ifstream highscore_file("assets/" + this->_gameNames[this->_indexGame] + "/highscore.txt");
    std::string line;
    std::vector<std::pair<std::string, size_t>> highscore;
    if (highscore_file.is_open()) {
        while (getline(highscore_file, line)) {
            std::string player_name = line.substr(0, line.find(":"));
            size_t score = std::stoi(line.substr(line.find(":") + 1));
            highscore.push_back(std::pair<std::string, size_t>(player_name, score));
        }
        highscore_file.close();
    } else
        std::cout << "Unable to open highscore file" << std::endl;
    std::ofstream ofs("assets/" + this->_gameNames[this->_indexGame] + "/highscore.txt", std::ofstream::trunc);
    if (_username.size() == 0)
        _username = "Unknown";
    highscore.push_back(std::pair<std::string, size_t>(this->_username, this->game->getSettings().getScore()));
    sort(highscore.begin(), highscore.end(), compare_score);
    for (std::vector<std::pair<std::string, size_t>>::iterator it = highscore.begin(); it != highscore.begin() + 3; it ++)
        ofs << it->first << ":" << it->second << std::endl;
    ofs.close();
}

void Core::ArcadeGame(void)
{
    if (!this->game->update(this->MouseInput, this->KeyboardInput))
        set_highscore();
    this->display->display(this->game);
}

int Core::loop(void)
{
    this->display->open();
    this->_IsRunning = true;
    while (_IsRunning) {
        this->KeyboardInput = this->display->getEventKeyboard();
        this->MouseInput = this->display->getEventClick();
        // std::cout << "keyboard : " << this->display->getEventKeyboard() <<std::endl;
        if (this->KeyboardInput != 0)
            this->check_input(this->KeyboardInput);
        if (this->_scene == core::Scene::MAIN) {
            this->ArcadeMenu();
        } else {
            this->ArcadeGame();
        }
    }
    return 0;
}

Core::~Core()
{
} // std::cout << "ici" << std::endl; // key Enter
  // this->check_input(KeyboardInput);