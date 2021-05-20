/*
** EPITECH PROJECT, 2021
** cpp_poolday15
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

template<typename T>
class array {
    public:
        array()
        {
            this->_tab = nullptr;
            this->_size = 0;
        }

        array(unsigned int size)
        {
            this->_tab = new T[size];
            this->_size = size;
        }

        array(array &other)
        {
            this->_tab = other._tab;
            this->_size = other._size;
        }

        T &operator[](unsigned int index)
        {
            
        }

        ~array()
        {
            if (this->_tab)
                delete this->_tab;
        }

    protected:
        T *_tab;
        int _size;
};

#endif /* !EX05_HPP_ */
