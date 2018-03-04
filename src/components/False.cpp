//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "False.hpp"

namespace nts {
    False::False(std::string name) : AComponent(name, "False") {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT, Tristate::FALSE)));
    }

    False::~False() {
    }

    Tristate False::compute(std::size_t pin) {
        if (pin != 1)
            throw (ComputeError("Requested pin index is out of range"));
        return _pins[pin - 1]->getValue();
    }
}
