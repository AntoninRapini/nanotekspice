//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#include "Pin.hpp"
#include "AComponent.hpp"

namespace nts
{	
	Pin::Pin(IComponent *owner, Type type, Tristate value) :
		_owner(owner), _type(type), _value(value), _isbeingcomputed(false)
	{
		_index = ((AComponent *)_owner)->getPins().size();
	}

	Tristate Pin::compute()
	{
		if (_value == Tristate::UNDEFINED)
		{
			if (_isbeingcomputed)
			{
				_isbeingcomputed = false;
				_value = Tristate::UNDEFINED;
			}
			else
			{
				_isbeingcomputed = true;
				_value = _owner->compute(_index);
			}
		}
		return _value;
	}
	
	Tristate Pin::getValue() const
	{
		return _value;
	}


	Pin::Type Pin::getType() const
	{
		return _type;
	}
	
	void Pin::setValue(nts::Tristate value)
	{
		_value = value;
	}

	const IComponent *Pin::getOwner() const
	{
		return _owner;
	}
}
