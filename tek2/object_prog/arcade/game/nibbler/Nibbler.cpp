/*
** EPITECH PROJECT, 2021
** nibbler
** File description:
** file
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    init_tiles("assets/nibbler/maps/map_level1.txt");
    init_objects("assets/nibbler/maps/map_level1.txt");
    init_player();
    init_settings();
    _timer = std::chrono::system_clock::now();
    _add_new_cell = false;
    _is_paused = false;
    _is_new_dir = false;
    _is_game_over = false;
    std::srand(time(NULL));
}

Nibbler::~Nibbler()
{
}

void Nibbler::create_object(nibbler_objects obj, Vector2i coords)
{
    init_obj_creator();

    for (std::unordered_map<nibbler_objects, Object (*)(Vector2i)>::iterator it = _objCreator.begin(); it != _objCreator.end(); it++)
    {
        if (obj == it->first)
            _objects.push_back(it->second(coords));
    }
}

void Nibbler::create_tile(nibbler_objects obj, Vector2i coords)
{
    init_tile_creator();

    for (std::unordered_map<nibbler_objects, Object (*)(Vector2i)>::iterator it = _tileCreator.begin(); it != _tileCreator.end(); it++)
    {
        if (obj == it->first)
            _tiles.push_back(it->second(coords));
    }
}

void Nibbler::init_objects(std::string map_to_load)
{
    std::ifstream file(map_to_load);
    std::string line;

    for (int y = 0; std::getline(file, line); y++)
        for (int x = 0; x < line.size(); x++)
            create_object((nibbler_objects)(line[x] - 48), Vector2i(x, y));
}

void Nibbler::init_player(void)
{
    for (int idx = 0; idx < _objects.size(); idx++)
    {
        if (_objects.at(idx).getContent() == Content::PLAYER)
        {
            Player tmp;
            tmp._index = idx;
            tmp._dir = Vector2i(1, 0);
            tmp._lastDir = Vector2i(1, 0);
            tmp._speed = 32;
            tmp._type = _map[_objects.at(idx).getCoords().y / 32][_objects.at(idx).getCoords().x / 32];
            tmp._is_sorted = false;
            if (tmp._type == HEAD)
                _headPos = _objects.at(idx).getCoords();
            _player.push_back(tmp);
        }
    }
    sort_player_vector();
}

void Nibbler::sort_player_vector()
{
    std::vector<Player> tmp;

    while (tmp.size() < _player.size())
        for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
        {
            if (tmp.size() == 0 && it->_type == HEAD)
                tmp.push_back(*it);
            else if (tmp.size() != 0)
                if ((_objects.at(it->_index).getCoords().x == _objects.at(tmp[tmp.size() - 1]._index).getCoords().x + 32 && _objects.at(it->_index).getCoords().y == _objects.at(tmp[tmp.size() - 1]._index).getCoords().y) || (_objects.at(it->_index).getCoords().x == _objects.at(tmp[tmp.size() - 1]._index).getCoords().x - 32 && _objects.at(it->_index).getCoords().y == _objects.at(tmp[tmp.size() - 1]._index).getCoords().y) || (_objects.at(it->_index).getCoords().x == _objects.at(tmp[tmp.size() - 1]._index).getCoords().x && _objects.at(it->_index).getCoords().y == _objects.at(tmp[tmp.size() - 1]._index).getCoords().y + 32) || (_objects.at(it->_index).getCoords().x == _objects.at(tmp[tmp.size() - 1]._index).getCoords().x && _objects.at(it->_index).getCoords().y == _objects.at(tmp[tmp.size() - 1]._index).getCoords().y - 32))
                    if (it->_type != HEAD && it->_is_sorted == false)
                    {
                        tmp.push_back(*it);
                        it->_is_sorted = true;
                    }
        }
    _player = tmp;
}

void Nibbler::init_tiles(std::string map_to_load)
{
    std::ifstream file(map_to_load);
    std::string line;

    for (int y = 0; std::getline(file, line); y++)
    {
        std::vector<nibbler_objects> tmp;
        for (int x = 0; x < line.size(); x++)
        {
            create_tile((nibbler_objects)(line[x] - 48), Vector2i(x, y));
            tmp.push_back((nibbler_objects)(line[x] - 48));
        }
        _map.push_back(tmp);
    }
}

void Nibbler::init_settings()
{
    _settings.setScore(0);
    _settings.setScene(Scene::GAME);
    _settings.setTimer(0);
    _settings.setMusicPath("assets/nibbler/songs/snake_song.wav");
    _settings.setAssetsFolderPath("assets/nibbler");
    _is_game_over = false;
}

bool Nibbler::update(Vector2i mouse, char key)
{
    auto now_timer = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = now_timer - _timer;
    this->handleMouseEvent(mouse);
    this->handleKeyEvent(key);
    double game_speed = 0.15 - (double)_settings.getScore() / (double)30000;
    if (_is_game_over) {
        _settings.setScore(0);
        _is_game_over = false;
    }
    if (diff.count() >= ((game_speed >= 0.06) ? game_speed : 0.06) && !_is_paused) {
        _timer = std::chrono::system_clock::now();
        dir_handling();
        setOrientation();
        movement();
        checkCollision();
        add_cell();
    }
    if (_is_game_over)
        return false;
    return true;
}

void Nibbler::handleMouseEvent(Vector2i mouse)
{
}

void Nibbler::handleKeyEvent(char key)
{
    switch (key)
    {
    case 'z':
        move_up();
        _is_paused = false;
        break;
    case 's':
        move_down();
        _is_paused = false;
        break;
    case 'q':
        move_left();
        _is_paused = false;
        break;
    case 'd':
        move_right();
        _is_paused = false;
        break;
    case 'p':
        _is_paused = _is_paused ? false : true;
    default:
        break;
    }
}

void Nibbler::movement(void)
{
    for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
    {
        if (it->_type == HEAD)
            _objects.at(it->_index).setCoords(Vector2i(_objects.at(it->_index).getCoords().x + (it->_dir.x * it->_speed), _objects.at(it->_index).getCoords().y + (it->_dir.y * it->_speed)));
        else
            _objects.at(it->_index).setCoords(Vector2i(_objects.at(it->_index).getCoords().x + (it->_lastDir.x * it->_speed), _objects.at(it->_index).getCoords().y + (it->_lastDir.y * it->_speed)));
    }
}

void Nibbler::dir_handling(void)
{
    for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
    {
        it->_lastDir = it->_dir;
        if (it != _player.begin())
            it->_dir = (it - 1)->_lastDir;
        _is_new_dir = false;
    }
}

void Nibbler::move_up(void)
{
    if (_player[0]._dir.x != 0 && _player[0]._dir.y != 1 && _is_new_dir == false)
    {
        _is_new_dir = true;
        _player[0]._lastDir = _player[0]._dir;
        _player[0]._dir = Vector2i(0, -1);
    }
}

void Nibbler::move_down(void)
{
    if (_player[0]._dir.x != 0 && _player[0]._dir.y != -1 && _is_new_dir == false)
    {
        _is_new_dir = true;
        _player[0]._lastDir = _player[0]._dir;
        _player[0]._dir = Vector2i(0, 1);
    }
}

void Nibbler::move_left(void)
{
    if (_player[0]._dir.x != 1 && _player[0]._dir.y != 0 && _is_new_dir == false)
    {
        _is_new_dir = true;
        _player[0]._lastDir = _player[0]._dir;
        _player[0]._dir = Vector2i(-1, 0);
    }
}

void Nibbler::move_right(void)
{
    if (_player[0]._dir.x != -1 && _player[0]._dir.y != 0 && _is_new_dir == false)
    {
        _is_new_dir = true;
        _player[0]._lastDir = _player[0]._dir;
        _player[0]._dir = Vector2i(1, 0);
    }
}

void Nibbler::checkCollision(void)
{
    for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++) {
        if (it->_type == HEAD) {
            for (std::vector<Object>::iterator obj = _objects.begin(); obj != _objects.end(); obj++) {
                if (obj->getCoords() == _objects.at(it->_index).getCoords() && !obj->isWalkable()) {
                    game_over();
                    break;
                }
            }
            Object *tile = getTileAt(_objects.at(it->_index).getCoords());
            if (tile && tile->getContent() == Content::WALL) {
                if (tile->getCoords() == _objects.at(it->_index).getCoords())
                    game_over();
                    break;
            }
        }
    }
    for (std::vector<Object>::iterator obj = _objects.begin(); obj != _objects.end(); obj++)
        for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
            if (it->_type == HEAD && obj->getContent() == Content::COLLECTABLE)
            {
                if (obj->getCoords().x == _objects.at(it->_index).getCoords().x && obj->getCoords().y == _objects.at(it->_index).getCoords().y)
                {
                    bool is_free_tile = false;
                    Vector2i new_fruit_pos;
                    while (!is_free_tile)
                    {
                        new_fruit_pos = Vector2i((rand() % 28 + 1) * 32, (rand() % 28 + 1) * 32);
                        if (!getObjAt(new_fruit_pos) && getTileAt(new_fruit_pos)->getContent() != Content::WALL)
                            is_free_tile = true;
                    }
                    obj->setCoords(new_fruit_pos);
                    this->_add_new_cell = true;
                }
            }
}

void Nibbler::reset(void)
{
    game_over();
}

void Nibbler::game_over(void)
{
    _objects.clear();
    _objCreator.clear();
    _player.clear();
    init_objects("assets/nibbler/maps/map_level1.txt");
    init_player();
    _add_new_cell = false;
    _is_paused = true;
    _is_new_dir = false;
    _is_game_over = true;
}

void Nibbler::setOrientation(void)
{
    for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
    {
        if (it->_type == HEAD)
        {
            if (it->_dir.x == 1 && it->_dir.y == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_head_right");
            else if (it->_dir.x == -1 && it->_dir.y == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_head_left");
            else if (it->_dir.x == 0 && it->_dir.y == 1)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_head_down");
            else if (it->_dir.x == 0 && it->_dir.y == -1)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_head_up");
        }
        if (it->_type == TAIL)
        {
            if (it->_dir.x == 1 && it->_dir.y == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_tail_right");
            else if (it->_dir.x == -1 && it->_dir.y == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_tail_left");
            else if (it->_dir.x == 0 && it->_dir.y == 1)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_tail_down");
            else if (it->_dir.x == 0 && it->_dir.y == -1)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_tail_up");
        }
        if (it->_type == BODY)
        {
            if (it->_dir.x == 0 && it->_lastDir.x == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_body_v");
            else if (it->_dir.y == 0 && it->_lastDir.y == 0)
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_body_h");
            else if ((it->_lastDir.y == -1 && it->_dir.x == 1) || (it->_lastDir.x == -1 && it->_dir.y == 1))
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_corner_up_right");
            else if ((it->_lastDir.x == 1 && it->_dir.y == 1) || (it->_lastDir.y == -1 && it->_dir.x == -1))
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_corner_up_left");
            else if ((it->_lastDir.y == 1 && it->_dir.x == 1) || (it->_lastDir.x == -1 && it->_dir.y == -1))
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_corner_down_right");
            else if ((it->_lastDir.x == 1 && it->_dir.y == -1) || (it->_lastDir.y == 1 && it->_dir.x == -1))
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_corner_down_left");
            else
                _objects.at(it->_index).setFilePath("assets/nibbler/sprites/snake_body_h");
        }
    }
}

Object *Nibbler::getObjAt(Vector2i pos)
{
    for (std::vector<Object>::iterator obj = _objects.begin(); obj != _objects.end(); obj++)
    {
        if (obj->getCoords() == pos)
            return &*obj;
    }
    return nullptr;
}

Object *Nibbler::getTileAt(Vector2i pos)
{
    for (std::vector<Object>::iterator tile = _tiles.begin(); tile != _tiles.end(); tile++)
    {
        if (tile->getCoords() == pos)
            return &*tile;
    }
    return nullptr;
}

Vector2i Nibbler::add_right(Object obj)
{
    if (getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 + 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32 + 1));
    else if (getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 - 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32  - 1));
    return (Vector2i(0, 0));
}

Vector2i Nibbler::add_left(Object obj)
{
    if (getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 - 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32  - 1));
    else if(getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 + 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32 + 1));
    return (Vector2i(0, 0));
}

Vector2i Nibbler::add_top(Object obj)
{
    if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32  - 1));
    else if(getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 + 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32 + 1));
    else if (getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 - 1, obj.getCoords().y / 32));
    return (Vector2i(0, 0));
}

Vector2i Nibbler::add_bottom(Object obj)
{
    if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y + 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32 + 1));
    else if (getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x - 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 - 1, obj.getCoords().y / 32));
    else if (getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)) && getTileAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x, obj.getCoords().y - 32)))
            return(Vector2i(obj.getCoords().x / 32, obj.getCoords().y / 32  - 1));
    else if(getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)) && getTileAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y))->getContent() != Content::WALL)
        if (!getObjAt(Vector2i(obj.getCoords().x + 32, obj.getCoords().y)))
            return(Vector2i(obj.getCoords().x / 32 + 1, obj.getCoords().y / 32));
    return (Vector2i(0, 0));
}

void Nibbler::add_cell()
{
    if (_add_new_cell)
    {
        Vector2i tail_pos(0, 0);
        _settings.setScore(_settings.getScore() + 100);

        for (std::vector<Player>::iterator it = _player.begin(); it != _player.end(); it++)
            if (it->_type == TAIL && _add_new_cell)
            {
                if (it->_lastDir == Vector2i(-1, 0))
                    tail_pos = add_right(_objects.at(it->_index));
                else if (it->_lastDir == Vector2i(1, 0))
                    tail_pos = add_left(_objects.at(it->_index));
                else if (it->_lastDir == Vector2i(0, 1))
                    tail_pos = add_top(_objects.at(it->_index));
                else if (it->_lastDir == Vector2i(0, -1))
                    tail_pos = add_bottom(_objects.at(it->_index));
                else {
                    game_over();
                    break;
                }
                it->_type = BODY;
                _objects.push_back(create_tail(tail_pos));
                _player.push_back(*(new Player(_objects.size() - 1, it->_lastDir, it->_lastDir)));
                setOrientation();
                _add_new_cell = false;
                break;
            }
        _add_new_cell = false;
    }
}