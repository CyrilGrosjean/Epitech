/*
** EPITECH PROJECT, 2021
** cpp_poolday17
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename Obj>
typename Obj::iterator do_find(Obj &obj, int nb)
{
    return (std::find(obj.begin(), obj.end(), nb));
}

#endif /* !FIND_HPP_ */
