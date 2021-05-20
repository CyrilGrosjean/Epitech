/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
        };

        Toy();
        Toy(ToyType type, const std::string &name, const std::string &file);
        ~Toy();

        ToyType getType(void) const {return (_type);}
        std::string const &getName(void) const {return (_name);}
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string const &getAscii(void) const {return (_picture.data);}
        Toy &operator=(const Toy &other);

    protected:
        std::string _name;
        ToyType _type;
        Picture _picture;
    private:
};

#endif /* !TOY_HPP_ */
