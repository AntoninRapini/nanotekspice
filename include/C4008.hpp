//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef C4008_HPP_
# define C4008_HPP_

#include "AComponent.hpp"

namespace nts
{
	class C4008 : public AComponent
	{
	public:
		C4008(std::string name);
		~C4008();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !C4008_HPP_ */
