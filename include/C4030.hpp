//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4030_HPP_
# define C4030_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4030 : public AComponent {
    public:
        C4030(std::string name);

        ~C4030();

        Tristate compute(std::size_t pin = 1);
    };
}

#endif /* !C4030_HPP_ */
