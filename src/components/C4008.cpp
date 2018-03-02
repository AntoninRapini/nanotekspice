//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "C4008.hpp"

namespace nts
{
	C4008::C4008(std::string name) : AComponent(name, "4008")
	{
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
	}

	C4008::~C4008()
	{
	}
	
	Tristate C4008::compute(std::size_t pin)
	{
                if (pin < 1 || pin > _pins.size())
                        throw(ComputeError("Requested pin index is out of range"));
                if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
                        throw(ComputeError("Requested pin cannot be computed"));
                if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
                        return _pins[pin - 1]->compute();
		Tristate B = _pins[5]->compute();
		Tristate A = _pins[6]->compute();
		Tristate C = _pins[8]->compute();
		C = ((A ^ B) ^ C) || ((A && B) && C);
		if (pin == 9)
			return C;
		B = _pins[3]->compute();
		A = _pins[4]->compute();
		C = ((A ^ B) ^ C) || ((A && B) && C);
		if (pin == 10)
			return C;
		B = _pins[1]->compute();
		A = _pins[2]->compute();
		C = ((A ^ B) ^ C) || ((A && B) && C);
		if (pin == 11)
			return C;
		B = _pins[13]->compute();
		A = _pins[0]->compute();
		C = ((A ^ B) ^ C) || ((A && B) && C);
		if (pin == 12)
			return C;
		return (A && B) || (B && C) || (A && C);
	}
}
