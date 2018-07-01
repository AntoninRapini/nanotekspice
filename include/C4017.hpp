//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4017_HPP_
# define C4017_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4017 : public AComponent {
    public:
        C4017(std::string name);
        ~C4017();
        Tristate compute(std::size_t pin = 1);
    };
}

#endif /* !C4017_HPP_ */
