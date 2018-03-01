//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4001_HPP_
# define C4001_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4001 : public AComponent
	{
	public:
		C4001(std::string name);
		~C4001();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4001_HPP_ */
