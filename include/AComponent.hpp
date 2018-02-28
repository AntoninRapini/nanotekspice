//
// EPITECH PROJECT, 2018
// NanoTekSpice
// File description:
// 
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

#include "LogicGates.hpp"
#include "Exceptions.hpp"
#include "Pin.hpp"
#include <vector>
#include <memory>

namespace nts
{
	class AComponent : public IComponent
	{
	public:
		AComponent(std::string name, std::string componentType);
		virtual ~AComponent() {};
		virtual Tristate compute(std::size_t pin = 1) = 0;
		const std::vector<std::shared_ptr<Pin>> &getPins() const;
		void setPinValue(std::size_t pin, Tristate value);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherpin);
		void dump() const;
	protected:
		std::vector<std::shared_ptr<Pin>> _pins;
		std::string _name;
		std::string _componentType;
	};
}

#endif /* !ACOMPONENT_HPP_ */
