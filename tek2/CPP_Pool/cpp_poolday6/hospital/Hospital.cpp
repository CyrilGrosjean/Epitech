/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** Hospital
*/

#include "Hospital.hpp"

Hospital::Hospital()
{
    doctors = nullptr;
    patients = nullptr;
    nurses = nullptr;
}

void Hospital::addDoctor(KoalaDoctorList *doctor)
{
    if (doctor == nullptr)
        return;
    if (doctors == nullptr) {
        doctors = doctor;
        return;
    }
    doctors->append(doctor);
}

void Hospital::addSick(SickKoalaList *patient)
{
    if (patient == nullptr)
        return;
    if (patients == nullptr) {
        patients = patient;
        return;
    }
    patients->append(patient);
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (nurse == nullptr)
        return;
    if (nurses == nullptr) {
        nurses = nurse;
        return;
    }
    nurses->append(nurse);
}

void Hospital::run(void)
{
    for (KoalaDoctorList *tmp = doctors; tmp; tmp = tmp->getNext()) {
        std::cout << "[HOSPITAL] Doctor " << tmp->getContent()->getName() <<
        " just arrived!" << std::endl;
        tmp->getContent()->timeCheck();
    }
    for (SickKoalaList *tmp = patients; tmp; tmp = tmp->getNext()) {
        std::cout << "[HOSPITAL] Patient " << tmp->getContent()->getName() <<
        " just arrived!" << std::endl;
    }
    for (KoalaNurseList *tmp = nurses; tmp; tmp = tmp->getNext()) {
        std::cout << "[HOSPITAL] Nurse " << tmp->getContent()->getID() <<
        " just arrived!" << std::endl;
        tmp->getContent()->timeCheck();
    }
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    doctors->dump();
    nurses->dump();
    patients->dump();
}

Hospital::~Hospital()
{
}
