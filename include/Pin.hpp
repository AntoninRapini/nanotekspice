//
// EPITECH PROJECT, 2018
// Nanotekspice
// File description:
// 
//

#ifndef PIN_HPP_
# define PIN_HPP_

#include "IComponent.hpp"

namespace nts
{
	class Pin
	{
	public:
		enum Type
		{
			INPUT,
			OUTPUT,
			IGNORED
		};
			Pin(IComponent *owner, Type type = Type::INPUT,
			    Tristate value = Tristate::UNDEFINED);
		Tristate compute();
		Tristate getValue() const;
		Type getType() const;
		void setValue(nts::Tristate value);
		const IComponent *getOwner() const;
	private:
		IComponent *_owner;
		Type _type;
		Tristate _value;
		size_t _index;
		bool _isbeingcomputed;
	};
}

#endif /* !PIN_HPP_ */
