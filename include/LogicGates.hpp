//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef LOGICGATES_HPP_
# define LOGICGATES_HPP_

#include "IComponent.hpp"

namespace nts
{
        Tristate operator&&(Tristate, Tristate);
        Tristate operator||(Tristate, Tristate);
	Tristate operator!(Tristate);
}

#endif /* !LOGICGATES_HPP_ */
