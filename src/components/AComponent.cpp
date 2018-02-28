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
		(*_pins[pin - 1]).setValue(value);
	}
	
	void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherpin)
	{
		if (pin >= 1 && pin <= _pins.size() &&
		    otherpin <= ((AComponent &)other)._pins.size())
		{
			if ((*_pins[pin - 1]).getOwner() == this)
			{
				if ((*_pins[pin - 1]).getType() != Pin::Type::INPUT)
					throw(LinkError("Pin can't be linked to"));
				if ((*((AComponent &)other)._pins[otherpin - 1]).getType()
				    != Pin::Type::OUTPUT)
					throw(LinkError("Pin can't link to other pins"));
				_pins[pin - 1] = ((AComponent &)other)._pins[otherpin - 1];
			}
			else
				throw(LinkError("Pin is already linked"));
		}
		else
			throw(LinkError("Requested pin index is out of range"));
	}

	void AComponent::dump() const
	{
		std::cout << _componentType << " : " << _name << std::endl;
	}
}
