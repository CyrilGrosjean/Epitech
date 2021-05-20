/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

class Ratatouille {
    public:
        Ratatouille();
        Ratatouille(Ratatouille const &other);
        Ratatouille &operator=(const Ratatouille &other);

        Ratatouille &addVegetable(unsigned char vegi);
        Ratatouille &addCondiment(unsigned int cond);
        Ratatouille &addSpice(double spice);
        Ratatouille &addSauce(const std::string &sauce);

        std::string kooc(void);

        ~Ratatouille();

    protected:
        std::ostringstream _stream;
    private:
};

#endif /* !RATATOUILLE_HPP_ */
