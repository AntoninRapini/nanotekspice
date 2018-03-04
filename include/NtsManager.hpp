//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef NTSMANAGER_HPP_
# define NTSMANAGER_HPP_

#include <map>
#include <memory>
#include "IComponent.hpp"
#include "AComponent.hpp"

namespace nts
{
	class NtsManager
	{
	public:
		void ChangePinValue(const std::string &name, Tristate value, std::size_t pin = 1, bool startup = false);
		void DisplayPinValue(const std::string &name, AComponent &component, std::size_t pin = 1);
		void Display();
		void Simulate();
		void Dump();
		std::map<std::string, std::unique_ptr<IComponent>> &getComponents();
	private:
		std::map<std::string, std::unique_ptr<IComponent>> _components;
	};
}

#endif /* !NTSMANAGER_HPP_ */
