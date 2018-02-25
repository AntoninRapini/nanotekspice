//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include "Pin.hpp"
#include <vector>
#include <memory>

namespace nts
{
	class AComponent
	{
	public:
		AComponent() = 0;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherpin);
		virtual void dump() const;
	private:
		std::vector<std::shared_ptr<Pin>> _pins;
	};
}

#endif /* !ACOMPONENT_HPP_
