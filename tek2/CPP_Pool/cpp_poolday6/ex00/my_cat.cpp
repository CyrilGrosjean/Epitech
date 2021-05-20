/*
** EPITECH PROJECT, 2021
** cpp_poolday6
** File description:
** my_cat
*/

#include "my_cat.hpp"

void get_cat(int ac, char **av)
{
    std::string noFile = ": No such file or directory";
    char content;

    for (int i = 1; i < ac; i += 1) {
        std::ifstream file(av[i]);
        if (!file.is_open()) {
            std::cerr << "my_cat: " << av[i] << noFile << std::endl;
        } else {
            content = file.get();
            for (; file.good(); content = file.get()) {
                std::cout << content;
            }
            file.close();
        }
    }
}