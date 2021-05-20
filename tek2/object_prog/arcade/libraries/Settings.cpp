/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Settings
*/

#include "../includes/Settings.hpp"

Settings::Settings()
{
    this->_assetsFolderPath = "";
    this->_musicPath = "";
    this->_scene = Scene::GAME;
    this->_score = 0;
    this->_timer = 0;
}

Settings::~Settings()
{
}
