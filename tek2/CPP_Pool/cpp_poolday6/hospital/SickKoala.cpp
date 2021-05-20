/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str): name(str)
{
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug != "Mars" && drug != "Kinder") {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return (false);
    }
    if (drug == "Mars")
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
    if (drug == "Kinder")
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
    return (true);
}

void SickKoala::overDrive(std::string text)
{
    std::string sub_str = "1337!";
    std::size_t index = 0;

    while ((index = text.find("Kreog!")) != std::string::npos) {
        text.replace(index, 6, sub_str);
    }
    std::cout << "Mr." << name << ": " << text << std::endl;
}

std::string SickKoala::getName(void)
{
    return (name);
}

SickKoala::~SickKoala(void)
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}
