
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    try : _api(input, output)
{
} catch (std::exception &e) {
    std::string error = static_cast<std::string>(e.what());
    throw CommunicationError("Error: " + error);
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    } catch (std::logic_error &e) {
        std::string error = static_cast<std::string>(e.what());
        throw CommunicationError("LogicError: " + error);
    } catch (std::runtime_error &e) {
        std::string error = static_cast<std::string>(e.what());
        throw CommunicationError("RuntimeError: " + error);
    } catch (std::exception &e) {
        std::string error = static_cast<std::string>(e.what());
        throw CommunicationError("Error: " + error);
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        message = "INVALID MESSAGE";
    }
}
