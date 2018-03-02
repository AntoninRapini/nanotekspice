//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Parser.hpp"
#include "ComponentFactory.hpp"

int main(int ac, char **args)
{
	nts::ComponentFactory cFactory;

	std::unique_ptr<nts::IComponent> cs(cFactory.createComponent("4081", "4081"));
	std::unique_ptr<nts::IComponent> i0(cFactory.createComponent("input", "i0"));
	std::unique_ptr<nts::IComponent> i1(cFactory.createComponent("input", "i1"));
	std::unique_ptr<nts::IComponent> i2(cFactory.createComponent("input", "i2"));
	std::unique_ptr<nts::IComponent> s(cFactory.createComponent("output", "s"));

	((nts::Input &)(*i0)).setPinValue(1, nts::Tristate::TRUE);
	((nts::Input &)(*i1)).setPinValue(1, nts::Tristate::TRUE);
	((nts::Input &)(*i2)).setPinValue(1, nts::Tristate::UNDEFINED);

	std::vector<nts::IComponent *> components;
	components.push_back(cs.get());;
	components.push_back(i0.get());
	components.push_back(i1.get());
	components.push_back(i2.get());
	components.push_back(s.get());

	components[0]->setLink(1, *components[1], 1);
	components[0]->setLink(2, *components[2], 1);
	components[0]->setLink(5, *components[0], 3);
	components[0]->setLink(6, *components[3], 1);
	components[4]->setLink(1, *components[0], 4);
	components[4]->compute(1);

	(void) ac;
	nts::Parser parser(cFactory, args[1]);
    parser.run();
	return (0);
}
