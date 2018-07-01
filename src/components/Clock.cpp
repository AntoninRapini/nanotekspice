//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Clock.hpp"

namespace nts {
    Clock::Clock(std::string name) : AComponent(name, "Clock") {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT, Tristate::UNDEFINED)));
    }

    Clock::~Clock() {
    }

    Tristate Clock::compute(std::size_t pin) {
        if (pin != 1)
        {
            if (pin == 0)
                _pins[pin -1]->setValue(!_pins[pin - 1]->getValue());
            else if (pin == 2)
                _pins[pin - 1]->setValue(Tristate::TRUE);
            else if (pin == 3)
                _pins[pin - 1]->setValue(Tristate::FALSE);
            else
                throw (ComputeError("Requested pin index is out of range"));
            return Tristate::UNDEFINED;
        }
        return _pins[pin - 1]->getValue();
    }
}
