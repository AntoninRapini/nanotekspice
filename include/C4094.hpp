//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4094_HPP_
# define C4094_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4094 : public AComponent
	{
	public:
		C4094(std::string name);
		~C4094();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4094_HPP_ */
