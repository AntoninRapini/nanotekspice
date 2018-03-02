//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
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
		{"input", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Input(value))); }},
		{"output", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Output(value))); }},
		{"clock", [](const std::string &value) -> std::unique_ptr<IComponent> { return (std::unique_ptr<IComponent>(new Clock(value))); }},
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
			(const std::string &type, const std::string &name, std::string const &value)
	{
		auto it = (_creationFuncs.find(type));

		if (it == _creationFuncs.end())
            throw ParsingError("Referred an invalid component type");

		return it->second(name);
	}
}
