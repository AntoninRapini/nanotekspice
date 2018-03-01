//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4514_HPP_
# define C4514_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4514 : public AComponent
	{
	public:
		C4514(std::string name);
		~C4514();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4514_HPP_ */
