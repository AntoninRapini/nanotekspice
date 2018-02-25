//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#include "AComponent.hpp"

void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherpin)
{
	if (pin >= 1 && pin < _pins.size() && otherpin < other._pins.size())
	{
		if ((*_pins[pin - 1])->link == &this)
			_pins[pin - 1] = other._pins[otherpin - 1];
		else
			throw(LinkError("Pin is already linked"));
	}
	else
		throw (LinkError("Requested pin index is out of range"));
}
