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
#include <iostream>
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
		const std::string &getType() const;
		const std::string &getName() const;
		void setPinValue(std::size_t pin, Tristate value);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherpin);
		void dump() const;
	protected:
		std::vector<std::shared_ptr<Pin>> _pins;
		std::string _name;
		std::string _componentType;
	};

	std::ostream &operator<<(std::ostream &os, Tristate value);
}


#endif /* !ACOMPONENT_HPP_ */
