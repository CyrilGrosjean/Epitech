/*
** EPITECH PROJECT, 2021
** obj creator
** File description:
** file
*/

#include "Nibbler.hpp"

Object Nibbler::create_body(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::PLAYER);
    obj.setFilePath("assets/nibbler/sprites/snake_body_h");
    obj.setSize(32);
    obj.setWalkable(false);
    obj.setColor(Vector3i(240, 95, 0));
    return obj;
}

Object Nibbler::create_head(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::PLAYER);
    obj.setFilePath("assets/nibbler/sprites/snake_head_right");
    obj.setSize(32);
    obj.setWalkable(true);
    obj.setColor(Vector3i(240, 25, 0));
    return obj;
}

Object Nibbler::create_tail(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::PLAYER);
    obj.setFilePath("assets/nibbler/sprites/snake_tail_right");
    obj.setSize(32);
    obj.setWalkable(false);
    obj.setColor(Vector3i(240, 75, 0));
    return obj;
}

Object Nibbler::create_fruit(Vector2i coords)
{
    Object obj;

    obj.setCoords(Vector2i(coords.x * 32, coords.y * 32));
    obj.setActive(true);
    obj.setContent(Content::COLLECTABLE);
    obj.setFilePath("assets/nibbler/sprites/fruit");
    obj.setSize(32);
    obj.setWalkable(true);
    obj.setColor(Vector3i(240, 150, 150));
    return obj;
}

void Nibbler::init_obj_creator()
{
    _objCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(BODY, &create_body));
    _objCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(HEAD, &create_head));
    _objCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(TAIL, &create_tail));
    _objCreator.insert(std::pair<nibbler_objects, Object (*)(Vector2i)>(FRUIT, &create_fruit));
}