/*
** EPITECH PROJECT, 2021
** DomesticKoala
** File description:
** DomesticKoala
*/

#include "KoalaAction.hpp"
#include <vector>
#include <iostream>
#include <string>

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

using methodPointer_t = void (KoalaAction::*)(const std::string &);

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &action);
        DomesticKoala(const DomesticKoala &other);
        DomesticKoala &operator=(const DomesticKoala &other);
        const std::vector<methodPointer_t> *getActions(void) const {return (&_actions);}
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &action);
        ~DomesticKoala();

    protected:
        KoalaAction _koalaAction;
        std::vector<methodPointer_t> _actions;
        std::vector<char> _keys;
    private:
};

#endif /* !DOMESTICKOALA_HPP_ */
