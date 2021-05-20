/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** set_asset
*/

#ifndef SET_ASSET_HPP_
#define SET_ASSET_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "../../includes/Vector.hpp"

namespace sdl
{
    class set_asset
    {
    private:
        /* data */
    public:
        set_asset(){};
        set_asset(SDL_Renderer *_renderer ,std::string , SDL_Rect, SDL_Rect , float , float);
        SDL_Texture *_texture;
        std::string _filepath;
        SDL_Surface *image;
        SDL_Rect _rect;
        SDL_Rect _anim;
        ~set_asset();
    };
}

#endif /* !SET_ASSET_HPP_ */
