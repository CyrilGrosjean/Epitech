/*
** EPITECH PROJECT, 2021
** cpp_poolday14_pm
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"
#include <memory>

SimplePtr::SimplePtr(BaseComponent *rawPtr):
_rawPtr(rawPtr)
{
}

SimplePtr::SimplePtr(SimplePtr const &other)
{
    _rawPtr = other._rawPtr;
}

BaseComponent *SimplePtr::get() const
{
    return (this->_rawPtr);
}

SimplePtr &SimplePtr::operator=(SimplePtr const &other)
{
    this->_rawPtr = other.get();
    return (*this);
}

SimplePtr::~SimplePtr()
{
    if (_rawPtr)
        delete _rawPtr;
}
