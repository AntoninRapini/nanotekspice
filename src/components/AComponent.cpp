//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
	AComponent::AComponent(std::string name, std::string componentType)
		: _name(name), _componentType(componentType)
	{
	}

	const std::vector<std::shared_ptr<Pin>> &AComponent::getPins() const
	{
		return (_pins);
	}

	void AComponent::setPinValue(std::size_t pin, Tristate value)
	{
		if (pin < 1 || pin > _pins.size())
			throw(SetError("Requested pin index is out of range"));
		_pins[pin - 1]->setValue(value);
	}

	const std::string &AComponent::getType() const
	{
		return (_componentType);
	}

	const std::string &AComponent::getName() const
	{
		return (_name);
	}
	
	void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherpin)
	{
		if (pin >= 1 && pin <= _pins.size() &&
		    otherpin <= ((AComponent &)other)._pins.size())
		{
			if (_pins[pin - 1]->getType() == Pin::Type::INPUT && ((AComponent &)other)._pins[otherpin - 1]->getType() == Pin::Type::OUTPUT)
			{
				if (_pins[pin - 1]->getOwner() == this)
				{
					_pins[pin - 1] = ((AComponent &)other)._pins[otherpin - 1];
				}
				else
					throw(LinkError("Pin is already linked"));
			}
			else if (_pins[pin - 1]->getType() == Pin::Type::OUTPUT && ((AComponent &)other)._pins[otherpin - 1]->getType() == Pin::Type::INPUT)
			{
				try
				{
					((AComponent &)other).setLink(otherpin, *this, pin);
				}
				catch (const LinkError &e)
				{
					throw (LinkError(e.what()));
				}
			}
			else
				throw(LinkError("Pins can't be linked together"));
		}
		else
			throw(LinkError("Requested pin index is out of range"));
	}

	void AComponent::dump() const
	{
		std::cout << _componentType << " : " << _name << std::endl;
	}

	std::ostream &operator<<(std::ostream &os, Tristate value)
	{
		char c = value == Tristate::UNDEFINED ? 'U' : value == Tristate::TRUE ? '1' : '0';
		os << c;
		return os;
	}
}
