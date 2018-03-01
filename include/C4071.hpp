//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4071_HPP_
# define C4071_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4071 : public AComponent
	{
	public:
		C4071(std::string name);
		~C4071();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4071_HPP_ */
