/*
** EPITECH PROJECT, 2021
** nibbler
** File description:
** header
*/

#ifndef NIBBLER_H_
#define NIBBLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include "../../includes/GameModule.hpp"
#include "../../includes/Scene.hpp"
#include "../../includes/Content.hpp"
#include "../../includes/Object.hpp"
#include "../../includes/Settings.hpp"
#include "../../includes/Vector.hpp"
#include "Player.hpp"
#include "content_e.hpp"

class Nibbler : public GameModule {
    public:
        Nibbler();
        ~Nibbler();
        bool update(Vector2i mouse, char key) override;
        void handleKeyEvent(char key) override;
        void handleMouseEvent(Vector2i mouse) override;

    private:
        //Init Functions
        void create_object(nibbler_objects obj, Vector2i coords);
        void create_tile(nibbler_objects obj, Vector2i coords);
        void init_objects(std::string map_to_load = "assets/nibbler/maps/map_level1.txt");
        void init_tiles(std::string map_to_load = "assets/nibbler/maps/map_level1.txt");
        void init_player(void);
        void sort_player_vector();
        void init_settings();

        //Objects Functions
        static Object create_body(Vector2i coords);
        static Object create_head(Vector2i coords);
        static Object create_tail(Vector2i coords);
        static Object create_fruit(Vector2i coords);
        void init_obj_creator();

        //Tiles Functions
        static Object create_floor(Vector2i coords);
        static Object create_wall(Vector2i coords);
        void init_tile_creator();

        //Movement Functions
        void movement();
        void dir_handling();
        void move_up();
        void move_down();
        void move_left();
        void move_right();

        //Finding Functions
        Object *getObjAt(Vector2i pos);
        Object *getTileAt(Vector2i pos);

        //Interaction Functions
        void checkCollision();
        void setOrientation();
        void game_over();
        void reset() override;

        //Adding functions
        void add_cell();
        Vector2i add_right(Object obj);
        Vector2i add_left(Object obj);
        Vector2i add_top(Object obj);
        Vector2i add_bottom(Object obj);

        //Variables
        std::unordered_map <nibbler_objects, Object (*)(Vector2i)> _objCreator;
        std::unordered_map <nibbler_objects, Object (*)(Vector2i)> _tileCreator;
        std::vector<std::vector<nibbler_objects>> _map;
        Vector2i _headPos;
        std::vector<Player> _player;
        bool _is_new_dir;
        bool _add_new_cell;
        std::chrono::_V2::system_clock::time_point _timer;
        bool _is_paused;
        bool _is_game_over;

    protected:
};

#endif /* !NIBBLER_H_ */