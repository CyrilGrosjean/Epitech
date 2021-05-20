/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "Vector.hpp"
#include "Content.hpp"

class Object {
    public:
        Object();
        ~Object();

        void setWalkable(bool walkable) {this->_walkable = walkable;};
        void setSize(std::size_t size) {this->_size = size;};
        void setCoords(Vector2i coords) {this->_coords = coords;};
        void setFilePath(std::string filePath) {this->_filePath = filePath;};
        void setActive(bool active) {this->_active = active;};
        void setColor(Vector3i color) {this->_color = color;};
        void setContent(Content content) {this->_content = content;};

        bool isWalkable(void) const {return this->_walkable;};
        bool isActive(void) const {return this->_active;};
        Vector2i getCoords(void) const {return this->_coords;};
        Vector3i getColor(void) const {return this->_color;};
        std::string getFilePath(void) const {return this->_filePath;};
        std::size_t getSize(void) const {return this->_size;};
        Content getContent(void) const {return this->_content;};

    protected:
        Vector2i _coords;
        Content _content;
        bool _walkable;
        bool _active;
        std::string _filePath;
        Vector3i _color;
        std::size_t _size;

};

#endif /* !OBJECT_HPP_ */
