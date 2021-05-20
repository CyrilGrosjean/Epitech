/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include "ISquad.hpp"
#include <list>
#include <iostream>

class Squad : public ISquad {
    public:
        Squad();
        int getCount(void) const;
        ISpaceMarine *getUnit(int index);
        int push(ISpaceMarine *marine);
        ~Squad();

    protected:
        std::list<ISpaceMarine> _marines;
    private:
};

#endif /* !SQUAD_HPP_ */
