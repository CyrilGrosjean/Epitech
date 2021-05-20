/*
** EPITECH PROJECT, 2021
** tile creator
** File description:
** file
*/

#include "Nibbler.hpp"

Object Nibbler::create_floor(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::FLOOR);
    obj.setFilePath("assets/nibbler/sprites/floor");
    obj.setSize(32);
    obj.setWalkable(true);
    obj.setColor(Vector3i(110, 180, 15));
    return obj;
}

Object Nibbler::create_wall(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::WALL);
    obj.setFilePath("assets/nibbler/sprites/wall");
    obj.setSize(32);
    obj.setWalkable(false);
    obj.setColor(Vector3i(130, 90, 0));
    return obj;
}

void Nibbler::init_tile_creator()
{
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(FLOOR, &create_floor));
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(HEAD, &create_floor));
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(BODY, &create_floor));
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(TAIL, &create_floor));
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(FRUIT, &create_floor));
    _tileCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(WALL, &create_wall));
}