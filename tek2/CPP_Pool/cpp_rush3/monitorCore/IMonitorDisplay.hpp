/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    public:

        virtual void displayModules(void) = 0;
        virtual void refreshModules(void) = 0;
        virtual void run(void) = 0;

    protected:
    private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
