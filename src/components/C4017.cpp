//
// Created by Mardel on 28/06/18.
//

#include "C4017.hpp"

namespace nts
{
	std::array<size_t, 12> C4017::OutputPins = {5, 1, 0, 2, 6, 7, 3, 8, 4, 9, 0, 0};

	C4017::C4017(std::string name) : AComponent(name, "4017"), _used(false), _clock1(Tristate::FALSE), _clock2(Tristate::FALSE)
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

	void C4017::Reset()
	{
		_used = false;
	}
	
	Tristate  C4017::compute(size_t pin)
	{
		if (pin < 1 || pin > _pins.size())
			throw (ComputeError("Requested pin index is out of range"));
		if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
			throw (ComputeError("Requested pin cannot be computed"));
		if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
			return _pins[pin - 1]->compute();
		Tristate clock = _pins[13]->compute();
		Tristate m = _pins[14]->compute();
		if (clock == Tristate::UNDEFINED || m == Tristate::UNDEFINED)
			return (Tristate::UNDEFINED);
		else if (m == Tristate::TRUE)
			_pinToCompute = 0;
		if (clock == Tristate::TRUE && _clock1 == Tristate::FALSE && !_used)
		{
			_used = true;
			_pinToCompute = (_pinToCompute + 1) % 10;
		}
		_clock1 = clock;
		if (OutputPins[pin - 1] == _pinToCompute || (pin == 12 && _pinToCompute < 5))
			return Tristate::TRUE;
		return Tristate::FALSE;
	}
}
