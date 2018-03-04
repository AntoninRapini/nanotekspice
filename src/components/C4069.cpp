//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "C4069.hpp"

namespace nts
{
	C4069::C4069(std::string name) : AComponent(name, "4069")
	{
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
	}

	C4069::~C4069()
	{
	}
	
	Tristate C4069::compute(std::size_t pin)
	{
                if (pin < 1 || pin > _pins.size())
                        throw(ComputeError("Requested pin index is out of range"));
                if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
                        throw(ComputeError("Requested pin cannot be computed"));
                if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
			return _pins[pin - 1]->compute();
		std::size_t pinA = pin > 7 ? pin + 1 : pin - 1;
		return !(_pins[pinA - 1]->compute());
	}
}
