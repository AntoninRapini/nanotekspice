//
// Created by Mardel on 28/06/18.
//

#include "C4514.hpp"

namespace nts
{
	std::array<size_t, 16> C4514::OutputPins = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16,15};

    C4514::C4514(std::string name) : AComponent(name, "4514"), _pinToCompute(0)
    {
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
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
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this, Pin::Type::OUTPUT)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
        _pins.push_back(std::shared_ptr<Pin>(new Pin(this)));
    }

    C4514::~C4514()
    {

    }

    Tristate  C4514::compute(size_t pin)
    {
	    if (pin < 1 || pin > _pins.size())
		    throw (ComputeError("Requested pin index is out of range"));
	    if (_pins[pin - 1]->getType() == Pin::Type::IGNORED)
		    throw (ComputeError("Requested pin cannot be computed"));
	    if (_pins[pin - 1]->getType() == Pin::Type::INPUT)
		    return _pins[pin - 1]->compute();
	    if (_pins[22]->compute() == Tristate::TRUE || _pins[22]->compute() == Tristate::UNDEFINED || _pins[0]->compute() == Tristate::UNDEFINED)
		    return (Tristate::FALSE);
	    if (_pins[0]->compute() == Tristate::TRUE)
	    {
		    if (_pins[1]->compute() == Tristate::UNDEFINED || _pins[2]->compute() == Tristate::UNDEFINED
			|| _pins[20]->compute() == Tristate::UNDEFINED || _pins[21]->compute() == Tristate::UNDEFINED)
			    return Tristate::UNDEFINED;
		    _pinToCompute = 0;
		if (_pins[1]->compute() == Tristate::TRUE)
			_pinToCompute += 1;
		if (_pins[2]->compute() == Tristate::TRUE)
			_pinToCompute += 2;
		if (_pins[20]->compute() == Tristate::TRUE)
			_pinToCompute += 4;
		if (_pins[21]->compute() == Tristate::TRUE)
			_pinToCompute += 8;
	    }
	    return (pin - 1 == OutputPins[_pinToCompute] - 1 ? TRUE : FALSE);
    }
}
