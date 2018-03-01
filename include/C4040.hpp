//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4040_HPP_
# define C4040_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4040 : public AComponent
	{
	public:
		C4040(std::string name);
		~C4040();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4040_HPP_ */
