/*
** EPITECH PROJECT, 2021
** player
** File description:
** file
*/

#include "Player.hpp"

Player::Player()
{
}

Player::Player(int index, Vector2i dir, Vector2i lastDir)
{
    _index = index;
    _dir = dir;
    _lastDir = lastDir;
    _speed = 32;
    _type = TAIL;
    _is_sorted = true;
}

Player::~Player()
{
}