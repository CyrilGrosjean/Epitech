/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

#include <map>
#include <string>
#include <fstream>

class BF_Translator {
    public:
        BF_Translator();
        int translate(const std::string &in, const std::string &out);
        ~BF_Translator();

    protected:
        std::map<char, std::string> _methods;
    private:
};

#endif /* !BF_TRANSLATOR_HPP_ */
