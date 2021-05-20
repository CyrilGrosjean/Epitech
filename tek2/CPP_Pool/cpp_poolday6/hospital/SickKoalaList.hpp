/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *patient);
        bool isEnd(void);
        void append(SickKoalaList *object);
        SickKoala *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *elemToRemove);
        SickKoalaList *removeFromName(std::string nameToRemove);
        SickKoala *getContent(void);
        SickKoalaList *getNext(void);
        void dump(void);
        ~SickKoalaList();

    protected:
    private:
        SickKoala *koala;
        SickKoalaList *next;
};

#endif /* !SICKKOALALIST_HPP_ */
