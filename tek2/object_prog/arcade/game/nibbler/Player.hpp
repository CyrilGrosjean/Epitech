/*
** EPITECH PROJECT, 2021
** Plaoyer
** File description:
** header file
*/

#ifndef NIBBLER_PLAYER_H_
#define NIBBLER_PLAYER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "../../includes/GameModule.hpp"
#include "../../includes/Scene.hpp"
#include "../../includes/Content.hpp"
#include "../../includes/Object.hpp"
#include "../../includes/Settings.hpp"
#include "../../includes/Vector.hpp"
#include "content_e.hpp"

class Player {
    public:
        Player();
        Player(int index, Vector2i dir, Vector2i lastDir);
        ~Player();
        int _index;
        Vector2i _dir;
        Vector2i _lastDir;
        std::size_t _speed;
        nibbler_objects _type;
        bool _is_sorted;

    protected:
    private:
};

#endif /* !NIBBLER_PLAYER_H_ */