/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"
#include <iostream>

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *doctor);
        bool isEnd(void);
        void append(KoalaDoctorList *object);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *elemToRemove);
        KoalaDoctorList *removeFromName(std::string nameToRemove);
        KoalaDoctor *getContent(void);
        KoalaDoctorList *getNext(void);
        void dump(void);
        ~KoalaDoctorList();

    protected:
    private:
        KoalaDoctor *koala;
        KoalaDoctorList *next;
};

#endif /* !KOALADOCTORLIST_HPP_ */
