/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** PacmanException
*/

#ifndef PACMANEXCEPTION_HPP_
#define PACMANEXCEPTION_HPP_

#include <string>

class PacmanException : public std::exception {
    public:
        PacmanException(std::string what);

        const char *what(void) const noexcept;

        ~PacmanException();

    protected:
        std::string _what;
};

class ObjectError : public PacmanException {
    public:
        ObjectError(std::string what);
        ~ObjectError();
};

#endif /* !PACMANEXCEPTION_HPP_ */
