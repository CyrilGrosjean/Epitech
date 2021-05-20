/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Object
*/

#include "../includes/Object.hpp"

Object::Object()
{
    this->_walkable = true;
    this->_coords = Vector2i(0, 0);
    this->_content = Content::FLOOR;
    this->_filePath = "";
    this->_active = true;
    this->_color = Vector3i(255, 255, 255);
    this->_size = 0;
}

Object::~Object()
{
}
