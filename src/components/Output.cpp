//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Output.hpp"

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

		_value = Tristate::UNDEFINED;
		if (pin != 1)
			throw(ComputeError("Requested pin index is out of range"));
		if (*_pins[pin - 1].getOwner() != this)
			_value = (*_pins[pin - 1]).compute();
		state = _value == Tristate::UNDEFINED ? 'U' : _value == Tristate::TRUE ? '1' : '0';
		std::cout << _name << "=" << state << std::endl;
		return _value;
	}
}
