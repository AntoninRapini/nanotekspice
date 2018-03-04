//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
    public:
        Clock(std::string name);

        ~Clock();

        Tristate compute(std::size_t pin = 1);
    };
}

#endif /* !CLOCK_HPP_ */
