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
		Pin(Tristate value = Tristate::UNDEFINED);
		Tristate getValue() const;
		void setValue(nts::Tristate value);
		IComponent *getLink() const;
		void setLink(IComponent *link);
	private:
		bool _isoutput;
		Tristate _value;
		IComponent *_link;
	};
}

#endif /* !PIN_HPP_ */
