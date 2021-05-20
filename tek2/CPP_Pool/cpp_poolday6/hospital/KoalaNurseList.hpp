/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *value);
        bool isEnd(void);
        void append(KoalaNurseList *newValue);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *elemToRemove);
        KoalaNurseList *removeFromID(int id);
        KoalaNurse *getContent(void);
        KoalaNurseList *getNext(void);
        void dump(void);
        ~KoalaNurseList();

    protected:
    private:
        KoalaNurse *nurse;
        KoalaNurseList *next;
};

#endif /* !KOALANURSELIST_HPP_ */
