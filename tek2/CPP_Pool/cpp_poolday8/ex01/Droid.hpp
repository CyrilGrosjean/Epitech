/*
** EPITECH PROJECT, 2021
** cpp_poolday8
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(const Droid &droid);
        Droid(std::string id);
        std::string getId(void) const;
        size_t getEnergy(void) const;
        size_t getAttack(void) const;
        size_t getToughness(void) const;
        std::string getStatus(void) const;
        DroidMemory *getBattleData(void) const;
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setBattleData(DroidMemory *battleData);
        Droid &operator=(const Droid &other);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        Droid &operator<<(size_t &energy);
        ~Droid();

    protected:
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
        DroidMemory *_battleData;
};

std::ostream &operator<<(std::ostream &s, const Droid &droid);

#endif /* !DROID_HPP_ */
