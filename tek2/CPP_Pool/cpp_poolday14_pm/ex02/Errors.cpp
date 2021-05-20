/*
** EPITECH PROJECT, 2021
** cpp_poolday14_pm
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

const char *NasaError::what(void) const noexcept
{
    return (_message.data());
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component):
NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component):
NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component):
NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message):
NasaError(message, "CommunicationDevice")
{
}