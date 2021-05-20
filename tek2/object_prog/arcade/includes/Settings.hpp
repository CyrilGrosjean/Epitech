/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <string>
#include <map>
#include "Scene.hpp"

class Settings {
    public:
        Settings();
        ~Settings();

        void setScore(std::size_t score) {this->_score = score;};
        void setTimer(std::size_t timer) {this->_timer = timer;};
        void setMusicPath(std::string musicPath) {this->_musicPath = musicPath;};
        void setAssetsFolderPath(std::string assetsFolderPath) {this->_assetsFolderPath = assetsFolderPath;};
        void setScene(Scene scene) {this->_scene = scene;};

        std::size_t getScore(void) const {return this->_score;};
        std::size_t getTimer(void) const {return this->_timer;};
        std::string getMusicPath(void) const {return this->_musicPath;};
        std::string getAssetsFolderPath(void) const {return this->_assetsFolderPath;};
        Scene getScene(void) const {return this->_scene;};

        std::string _playerName;

    protected:
        std::size_t _score;
        std::size_t _timer;
        std::string _musicPath;
        std::string _assetsFolderPath;
        Scene _scene;
};

#endif /* !SETTINGS_HPP_ */
