//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
	class Output : public AComponent
	{
	public:
		Output(std::string name);
		~Output();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !OUTPUT_HPP_ */
