/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &file);
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(const Picture &other);
        ~Picture();

        std::string data;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
