//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"

int main()
{
	nts::C4081 cs("4081");
	nts::Input i0("i0");
	nts::Input i1("i1");
	nts::Output s("s");
	i0.setPinValue(1, nts::Tristate::TRUE);
	std::vector<nts::IComponent *> components;
	components.push_back(&cs);
	components.push_back(&i0);
	components.push_back(&i1);
	components.push_back(&s);
	components[0]->setLink(1, *components[1], 1);
	components[0]->setLink(2, *components[2], 1);
	components[3]->setLink(1, *components[0], 3);
	components[3]->compute(1);
	return (0);
}
