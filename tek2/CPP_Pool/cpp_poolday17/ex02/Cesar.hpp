/*
** EPITECH PROJECT, 2021
** cpp_poolday17
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : public IEncryptionMethod {
    public:
        Cesar();
        virtual void encryptChar(char plainChar);
        virtual void decryptChar(char cipherChar);
        virtual void reset(void);
        virtual ~Cesar();

    protected:
        int _decal;
    private:
};

#endif /* !CESAR_HPP_ */
