/*
** EPITECH PROJECT, 2021
** cpp_poolday8
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        size_t getFingerprint(void) const;
        size_t getExp(void) const;
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);
        DroidMemory &operator<<(const DroidMemory &other);
        DroidMemory &operator>>(DroidMemory &other);
        DroidMemory &operator+=(const DroidMemory &other);
        DroidMemory &operator+=(const size_t &exp);
        DroidMemory operator+(const DroidMemory &other);
        DroidMemory operator+(const size_t &exp);
        DroidMemory &operator=(const DroidMemory &other);
        ~DroidMemory();

    protected:
    private:
        size_t _fingerprint;
        size_t _exp;
};

std::ostream &operator<<(std::ostream &s, const DroidMemory &memory);

#endif /* !DROIDMEMORY_HPP_ */
