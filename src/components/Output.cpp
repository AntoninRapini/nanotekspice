//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Output.hpp"
#include <iostream>

namespace nts
{
	Output::Output(std::string name) : AComponent(name, "Output")
	{
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
	}

	Output::~Output()
	{
	}
	
	Tristate Output::compute(std::size_t pin)
	{
		char state;
		Tristate value;

		value = Tristate::UNDEFINED;
		if (pin != 1)
			throw(ComputeError("Requested pin index is out of range"));
		if ((*_pins[pin - 1]).getOwner() != this)
			value = (*_pins[pin - 1]).compute();
		state = value == Tristate::UNDEFINED ? 'U' : value == Tristate::TRUE ? '1' : '0';
		std::cout << _name << "=" << state << std::endl;
		return value;
	}
}
