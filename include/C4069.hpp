//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4069_HPP_
# define C4069_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4069 : public AComponent
	{
	public:
		C4069(std::string name);
		~C4069();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4069_HPP_ */
