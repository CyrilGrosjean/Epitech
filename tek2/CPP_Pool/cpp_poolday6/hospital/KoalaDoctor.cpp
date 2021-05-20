/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string str): name(str)
{
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?"
    << std::endl;
    isWorking = false;
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    const std::string drug[5] = {"Mars", "Kinder", "Crunch", "Maroilles",
    "Eucalyptus leaf"};
    std::string fileName = patient->getName() + ".report";
    int index = random() % 5;
    std::fstream file;

    std::cout << "Dr." << name << ": So what's goerking you Mr." <<
    patient->getName() << "?" << std::endl;
    patient->poke();
    file.open(fileName);
    if (file.is_open()) {
        file << drug[index];
    }
    file.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (isWorking) {
        isWorking = false;
        std::cout << "Dr." << name << ": Time to go home to my eucalyptus " <<
        "forest!" << std::endl;
    } else {
        isWorking = true;
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
    }
}

std::string KoalaDoctor::getName(void)
{
    return (name);
}

KoalaDoctor::~KoalaDoctor(void)
{
}