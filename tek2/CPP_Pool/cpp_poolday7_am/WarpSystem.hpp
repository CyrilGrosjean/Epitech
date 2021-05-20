/*
** EPITECH PROJECT, 2021
** cpp_poolday7_am
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {

    class QuantumReactor {
        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);
            ~QuantumReactor();
        protected:
        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *reactor);
            QuantumReactor *checkReactor(void);
            ~Core();

        protected:
        private:
            QuantumReactor *_coreReactor;
    };

};

#endif /* !WARPSYSTEM_HPP_ */
