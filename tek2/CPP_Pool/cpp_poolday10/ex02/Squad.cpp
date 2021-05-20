/*
** EPITECH PROJECT, 2021
** cpp_poolday10
** File description:
** Squad
*/

#include "Squad.hpp"
#include <algorithm>

Squad::Squad()
{
}

int Squad::push(ISpaceMarine *marine)
{
    if (std::find(_marines.begin(), _marines.end(), *marine) != _marines.end())
        return (0);
    _marines.push_front(*marine);
    return ((int) _marines.size());
}

int Squad::getCount(void) const
{
    return ((int) _marines.size());
}

ISpaceMarine *Squad::getUnit(int index)
{
    if ((int) _marines.size() > index) {
        auto m_front = _marines.begin();

        std::advance(m_front, index);
        return (&*m_front);
    }
    return (nullptr);
}

Squad::~Squad()
{
}
