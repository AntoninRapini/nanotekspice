//
// Created by Mardel on 28/06/18.
//

#include "C4040.hpp"

namespace nts
{
	std::array<size_t, 15> C4040::OutputPins = {11, 5, 4, 6, 3, 2, 1, 0, 0, 0, 0, 8, 7, 9, 10};

	C4040::C4040(std::string name) : AComponent(name, "4040"), _clock(Tristate::FALSE)
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
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
		_pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::IGNORED)));
	}

	C4040::~C4040()
	{

	}

	Tristate  C4040::compute(size_t pin)
	{
		if (pin < 1 || pin > _pins.size())
			throw (ComputeError("Requested pin index is out of range"));
		if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
			throw (ComputeError("Requested pin cannot be computed"));
		if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
			return _pins[pin - 1]->compute();
		if (pin == 3 && _pins[12]->getOwner() == this)
		{
			if (_pinToCompute == 16)
				return Tristate::TRUE;
			return Tristate::FALSE;
		}
		Tristate clock = _pins[9]->compute();
		Tristate r = _pins[10]->compute();
		if (clock == Tristate::UNDEFINED && r == Tristate::UNDEFINED)
			return Tristate::UNDEFINED;
		else if (r == Tristate::TRUE)
			_pinToCompute = 0;
		else if (clock == Tristate::FALSE && _clock == Tristate::TRUE)
			_pinToCompute += 1;
		_clock = clock;
		int tmpPin = OutputPins[pin - 1];
		if ((_pinToCompute >> tmpPin) & 1)
			return Tristate::TRUE;
		return Tristate::FALSE;
	}
}
