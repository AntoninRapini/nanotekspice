//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "C4013.hpp"

namespace nts
{
	C4013::C4013(std::string name) : AComponent(name, "4013")
	{
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
	}

	C4013::~C4013()
	{
	}
	
	Tristate C4013::compute(std::size_t pin)
	{
		if (pin < 1 || pin > _pins.size())
			throw(ComputeError("Requested pin index is out of range"));
		if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
			throw(ComputeError("Requested pin cannot be computed"));
		if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
			return _pins[pin - 1]->compute();

		Tristate CL = _pins[pin == 1 || pin == 2 ? 2 : 10]->getValue(); //TODO: j'ai mis ->getValue, jsp ce que tu voulais ;)
		Tristate R = _pins[pin == 1 || pin == 2 ? 3 : 9]->getValue();
		Tristate D = _pins[pin == 1 || pin == 2 ? 4 : 8]->getValue();
		Tristate S = _pins[pin == 1 || pin == 2 ? 5 : 7]->getValue();

		if (R == Tristate::UNDEFINED || S == Tristate::UNDEFINED)
			return Tristate::UNDEFINED;
		if (R == Tristate::TRUE || S == Tristate::TRUE)
		{
			_pins[pin == 1 || pin == 2 ? 0 : 12]->setValue(Tristate::TRUE);
			_pins[pin == 1 || pin == 2 ? 1 : 11]->setValue(Tristate::TRUE);
			return Tristate::TRUE;
		}
		else if (R == Tristate::TRUE || (D == Tristate::FALSE && CL == Tristate::TRUE))
		{
			_pins[pin == 1 || pin == 2 ? 0 : 12]->setValue(Tristate::FALSE);
			_pins[pin == 1 || pin == 2 ? 1 : 11]->setValue(Tristate::TRUE);
		}
		else if (S == Tristate::TRUE || (D == Tristate::TRUE && CL == Tristate::TRUE))
		{
			_pins[pin == 1 || pin == 2 ? 0 : 12]->setValue(Tristate::TRUE);
			_pins[pin == 1 || pin == 2 ? 1 : 11]->setValue(Tristate::FALSE);
		}
		else if (D == Tristate::UNDEFINED || CL == Tristate::UNDEFINED)
			return Tristate::UNDEFINED;
		return (_pins[pin - 1]->getValue());
	}
}
