//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4081_HPP_
# define C4081_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4081 : public AComponent
	{
	public:
		C4081(std::string name);
		~C4081();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4081_HPP_ */
