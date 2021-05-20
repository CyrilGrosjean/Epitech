/*
** EPITECH PROJECT, 2021
** cpp_poolday7_pm
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Arms {
    public:
        Arms(std::string const &serial, bool functionnal);
        bool isFunctionnal();
        std::string const &serial();
        void informations();
        ~Arms();
    protected:
    private:
        const std::string &_name;
        bool _functionnal;
};

class Legs {
    public:
        Legs(std::string const &serial, bool functionnal);
        bool isFunctionnal();
        std::string const &serial();
        void informations();
        ~Legs();
    protected:
    private:
        const std::string &_name;
        bool _functionnal;
};

class Head {
    public:
        Head(std::string const &serial, bool functionnal);
        bool isFunctionnal();
        std::string const &serial();
        void informations();
        ~Head();
    protected:
    private:
        const std::string &_name;
        bool _functionnal;
};

#endif /* !PARTS_HPP_ */
