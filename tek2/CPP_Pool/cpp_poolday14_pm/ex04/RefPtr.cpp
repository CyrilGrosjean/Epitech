/*
** EPITECH PROJECT, 2021
** cpp_poolday14_pm
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr():
_rawPtr(nullptr)
{
}

RefPtr::RefPtr(BaseComponent *rawPtr):
_rawPtr(rawPtr)
{
}

RefPtr::RefPtr(RefPtr const &other)
{
    _rawPtr = other._rawPtr;
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    if (this->_rawPtr)
        delete this->_rawPtr;
    this->_rawPtr = other._rawPtr;
    return (*this);
}

BaseComponent *RefPtr::get() const
{
    return (this->_rawPtr);
}

RefPtr::~RefPtr()
{
}
