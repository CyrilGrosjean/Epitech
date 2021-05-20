/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(): _stability(true)
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor):
_coreReactor(reactor)
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return (_coreReactor);
}

WarpSystem::Core::~Core()
{
}
