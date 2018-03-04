//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "C4011.hpp"

namespace nts {
    C4011::C4011(std::string name) : AComponent(name, "4011") {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
    }

    C4011::~C4011() {
    }

    Tristate C4011::compute(std::size_t pin) {
        if (pin < 1 || pin > _pins.size())
            throw (ComputeError("Requested pin index is out of range"));
        if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
            throw (ComputeError("Requested pin cannot be computed"));
        if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
            return _pins[pin - 1]->compute();
        size_t pinA;
        size_t pinB;
        pinA = pin == 3 ? 1 : pin == 4 ? 5 : pin == 10 ? 8 : 12;
        pinB = pin == 3 ? 2 : pin == 4 ? 6 : pin == 10 ? 9 : 13;
        return !(_pins[pinA - 1]->compute() && _pins[pinB - 1]->compute());
    }
}
