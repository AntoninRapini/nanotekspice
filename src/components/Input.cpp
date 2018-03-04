//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Input.hpp"

namespace nts {
    Input::Input(std::string name) : AComponent(name, "Input") {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
    }

    Input::~Input() {
    }

    Tristate Input::compute(std::size_t pin) {
        if (pin != 1)
            throw (ComputeError("Requested pin index is out of range"));
        return _pins[pin - 1]->getValue();
    }
}
