//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

#include "AComponent.hpp"

namespace nts
{
	class False : public AComponent
	{
	public:
		False(std::string name);
		~False();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !FALSE_HPP_ */
