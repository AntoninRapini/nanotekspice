//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4013_HPP_
# define C4013_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4013 : public AComponent
	{
	public:
		C4013(std::string name);
		~C4013();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4013_HPP_ */
