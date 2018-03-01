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
#include "C4071.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4001.hpp"

namespace nts
{
	ComponentFactory::CreationFuncMap ComponentFactory::_creationFuncs
	{
		{"Input", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Input(value))); }},
		{"Output", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Output(value))); }},
		{"Clock", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Clock(value))); }},
		{"4081", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4081(value))); }},
		{"4071", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4071(value))); }},
		{"4011", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4011(value))); }},
		{"4030", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4030(value))); }},
		{"4001", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new C4001(value))); }}
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
