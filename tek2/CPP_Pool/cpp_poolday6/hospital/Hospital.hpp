/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"

class Hospital {
    public:
        Hospital();
        void addDoctor(KoalaDoctorList *doctor);
        void addSick(SickKoalaList *patient);
        void addNurse(KoalaNurseList *nurse);
        void run(void);
        ~Hospital();

    protected:
    private:
        KoalaDoctorList *doctors;
        KoalaNurseList *nurses;
        SickKoalaList *patients;
};

#endif /* !HOSPITAL_HPP_ */
