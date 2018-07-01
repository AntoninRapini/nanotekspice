//
// Created by Mardel on 28/06/18.
//

#include "C4040.hpp"

namespace nts
{
    C4017::C4017(std::string name) : AComponent(name, "4017")
    {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
    }

    C4017::~C4017()
    {

    }

    Tristate  C4017::compute(size_t pin)
    {
        if (pin < 1 || pin > _pins.size())
            throw (ComputeError("Requested pin index is out of range"));
        if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
            throw (ComputeError("Requested pin cannot be computed"));
        if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
            return _pins[pin - 1]->compute();
    }

}