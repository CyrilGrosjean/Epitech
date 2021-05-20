/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int identifier): id(identifier)
{
    isWorking = false;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::fstream file;
    std::string koalaName = filename.substr(0, filename.find_last_of("."));
    std::string drug = "";

    if (filename.substr(filename.find_last_of(".")) == ".report") {
        file.open(filename);
        if (file.is_open()) {
            std::getline(file, drug);
            std::cout << "Nurse " << id << ": Kreog! Mr." << koalaName <<
            "needs a " << drug << "!" << std::endl;
            file.close();
        }
    }
    return (drug);
}

void KoalaNurse::timeCheck(void)
{
    if (!isWorking) {
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
        isWorking = true;
    } else {
        std::cout << "Nurse " << id <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
        isWorking = false;
    }
}

int KoalaNurse::getID(void)
{
    return (id);
}

KoalaNurse::~KoalaNurse(void)
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}
