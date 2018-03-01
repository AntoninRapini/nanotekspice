//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "ComponentFactory.hpp"

int main()
{
	nts::ComponentFactory cFactory;

	std::unique_ptr<nts::IComponent> cs(cFactory.createComponent("4081", "4081"));
	std::unique_ptr<nts::IComponent> i0(cFactory.createComponent("Input", "i0"));
	std::unique_ptr<nts::IComponent> i1(cFactory.createComponent("Input", "i1"));
	std::unique_ptr<nts::IComponent> i2(cFactory.createComponent("Input", "i2"));
	std::unique_ptr<nts::IComponent> s(cFactory.createComponent("Output", "s"));

	((nts::Input &)(*i0)).setPinValue(1, nts::Tristate::TRUE);
	((nts::Input &)(*i1)).setPinValue(1, nts::Tristate::TRUE);
	((nts::Input &)(*i2)).setPinValue(1, nts::Tristate::FALSE);

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
	return (0);
}
