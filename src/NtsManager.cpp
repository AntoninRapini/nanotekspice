//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "LogicGates.hpp"
#include "NtsManager.hpp"
#include "Exceptions.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

namespace nts
{
	NtsManager::NtsManager(const std::map<std::string,
			       const std::unique_ptr<IComponent> &> components) : _components(components)
	{
	}

	void NtsManager::ChangePinValue(const std::string &name, Tristate value, std::size_t pin)
	{
		try
		{
			AComponent &to_change = static_cast<AComponent &>((*_components.at(name)));
			if (to_change.getType().compare("Input") != 0)
				throw (SetError("Requested component is not modifiable"));
			to_change.setPinValue(pin, value);
		}
		catch (const std::out_of_range &e)
		{
			throw (SetError("Requested component does not exist"));
		}
		catch (const SetError &e)
		{
			throw (SetError(e.what()));
		}
	}

	void NtsManager::DisplayPinValue
	(const std::string &name, AComponent &component, std::size_t pin)
	{
		Tristate value = component.getPins()[pin - 1]->getValue();
		char state = value == Tristate::UNDEFINED
			? 'U' : value == Tristate::TRUE ? '1' : '0';
                std::cout << name << "=" << state << std::endl;
	}
	
	void NtsManager::Display()
	{
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (((AComponent &)(it->second)).getType().compare("Output") == 0)
				DisplayPinValue(it->first, ((AComponent &)(it->second)));
		}
	}

	void NtsManager::Simulate()
	{
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (((AComponent &)(it->second)).getType().compare("Output") == 0)
				it->second->compute();
		}
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (((AComponent &)(it->second)).getType().compare("Clock") == 0)
			{
				ChangePinValue(it->first, !((AComponent &)(it->second)).getPins()[0]->getValue());
			}
		}
	}

	void NtsManager::Dump()
	{
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			it->second->dump();
		}
	}
}
