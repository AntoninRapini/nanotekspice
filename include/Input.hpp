//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
	class Input : public AComponent
	{
	public:
		Input();
		~Input();
		Tristate compute(std::size_t pin = 1);
	};
}

#endif /* !INPUT_HPP_ */
