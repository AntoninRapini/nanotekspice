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
		NtsManager(const std::map<std::string, const std::unique_ptr<IComponent> &> components);
		void ChangePinValue(const std::string &name, Tristate value, std::size_t pin = 1);;
		void DisplayPinValue(const std::string &name, AComponent &component, std::size_t pin = 1);
		void Display();
		void Simulate();
		void Dump();
	private:
		const std::map<std::string, const std::unique_ptr<IComponent> &> &_components;
	};
}

#endif /* !NTSMANAGER_HPP_ */
