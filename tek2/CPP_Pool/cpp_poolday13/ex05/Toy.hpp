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
            BUZZ,
            WOODY,
        };

        Toy(ToyType type = BASIC_TOY, std::string name = "toy", std::string file = "");
        ~Toy();

        ToyType getType(void) {return (_type);}
        std::string getName(void) {return (_name);}
        void setName(std::string name);
        bool setAscii(std::string &file);
        std::string getAscii(void);
        Toy *operator=(Toy *other);
        void speak(std::string statement, bool isEs = false);
        bool speak_es(std::string statement);
        Toy &operator<<(std::string content);

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK,
                };

                static std::string what(void);
                static std::string where(void);
                static ErrorType type;
        };

    protected:
        std::string _name;
        ToyType _type;
        std::string _file;
        Picture _picture;
    private:
};

std::ostream &operator<<(std::ostream &s, Toy &toy);

#endif /* !TOY_HPP_ */
