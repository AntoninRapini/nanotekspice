//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "True.hpp"

namespace nts
{
	True::True(std::string name) : AComponent(name, "True")
	{
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT, Tristate::TRUE)));
	}

	True::~True()
	{
	}
	
	Tristate True::compute(std::size_t pin)
	{
		if (pin != 1)
			throw(ComputeError("Requested pin index is out of range"));
		return _pins[pin - 1]->getValue();
	}
}
