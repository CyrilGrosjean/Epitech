/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** set_asset
*/

#include "set_asset.hpp"

sdl::set_asset::set_asset(SDL_Renderer *_renderer, std::string texture_filepath, SDL_Rect rect, SDL_Rect anim, float size_x, float size_y)
{
	this->_texture = IMG_LoadTexture(_renderer,texture_filepath.c_str());
	this->_rect = rect;
	this->_anim = anim;
	this->_filepath = texture_filepath;
}

sdl::set_asset::~set_asset()
{
}