//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#include "Pin.hpp"

Pin::Pin() : _value(nts::Tristate::UNDEFINED), link(nullptr)
{
}

nts::Tristate Pin::getValue() const
{
	return _value;
}

void Pin::setValue(nts::Tristate value)
{
	_value = value;
}

IComponent *Pin::getLink() const
{
	return _link;
}

void Pin::setLink(IComponent *link)
{
	_link = link;
}
