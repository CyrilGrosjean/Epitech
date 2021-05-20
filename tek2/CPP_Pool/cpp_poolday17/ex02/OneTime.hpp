/*
** EPITECH PROJECT, 2021
** cpp_poolday17
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class OneTime : public IEncryptionMethod {
    public:
        OneTime(std::string key);
        virtual void encryptChar(char plainChar);
        virtual void decryptChar(char cipherChar);
        virtual void reset(void);
        virtual ~OneTime();

    protected:
        std::string _key;
        size_t _index;
    private:
};

#endif /* !ONETIME_HPP_ */
