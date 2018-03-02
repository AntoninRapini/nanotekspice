//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

#include "AComponent.hpp"

namespace nts
{
	class True : public AComponent
	{
	public:
		True(std::string name);
		~True();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !TRUE_HPP_ */
