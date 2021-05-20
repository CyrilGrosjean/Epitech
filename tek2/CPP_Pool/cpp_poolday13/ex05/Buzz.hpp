/*
** EPITECH PROJECT, 2021
** cpp_poolday13
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string name, std::string file = "buzz.txt");
        ~Buzz();

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
