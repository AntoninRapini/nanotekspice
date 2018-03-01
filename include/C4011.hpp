//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4011_HPP_
# define C4011_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4011 : public AComponent
	{
	public:
		C4011(std::string name);
		~C4011();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4011_HPP_ */
