//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "ComponentFactory.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "C4081.hpp"

namespace nts
{
	ComponentFactory::CreationFuncMap ComponentFactory::_creationFuncs
	{
		{"Input", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Input(value))); }},
		{"Output", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Output(value))); }},
		{"Clock", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Clock(value))); }},
		{"4081", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4081(value))); }}
	};
	
	ComponentFactory::ComponentFactory()
	{
	}

	std::unique_ptr<IComponent> ComponentFactory::createComponent
	(const std::string &type, const std::string &value)
	{
		auto func = (_creationFuncs.find(type))->second;
		return func(value);
	}
}
